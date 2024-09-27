use super::{
    sequence::{ScriptSequence, TransactionWithMetadata},
    *,
};
use crate::{
    cmd::{forge::script::receipts::wait_for_receipts, has_batch_support, has_different_gas_calc},
    init_progress,
    opts::WalletType,
    update_progress,
};
use ethers::{
    prelude::{Provider, Signer, SignerMiddleware, TxHash},
    providers::{JsonRpcClient, Middleware},
    types::transaction::eip2718::TypedTransaction,
    utils::format_units,
};
use eyre::{ContextCompat, WrapErr};
use foundry_common::{get_http_provider, RetryProvider};
use foundry_config::Chain;
use futures::StreamExt;
	@@ -188,9 +188,9 @@ impl ScriptArgs {
        }

        match signer {
            WalletType::Local(signer) => self.broadcast(signer, tx).await,
            WalletType::Ledger(signer) => self.broadcast(signer, tx).await,
            WalletType::Trezor(signer) => self.broadcast(signer, tx).await,
        }
    }

	@@ -277,43 +277,106 @@ impl ScriptArgs {
        for mut tx in txes.into_iter() {
            tx.change_type(is_legacy);

            if !self.skip_simulation {
                let typed_tx = tx.typed_tx_mut();

                if has_different_gas_calc(chain) {
                    self.estimate_gas(typed_tx, &provider).await?;
                }

                total_gas += *typed_tx.gas().expect("gas is set");
            }

            new_txes.push_back(tx);
        }

        if !self.skip_simulation {
            // We don't store it in the transactions, since we want the most updated value. Right
            // before broadcasting.
            let per_gas = if let Some(gas_price) = self.with_gas_price {
                gas_price
            } else {
                match new_txes.front().unwrap().typed_tx() {
                    TypedTransaction::Legacy(_) | TypedTransaction::Eip2930(_) => {
                        provider.get_gas_price().await?
                    }
                    TypedTransaction::Eip1559(_) => provider.estimate_eip1559_fees(None).await?.0,
                }
            };

            println!("\n==========================");
            println!("\nEstimated total gas used for script: {}", total_gas);
            println!(
                "\nEstimated amount required: {} ETH",
                format_units(total_gas.saturating_mul(per_gas), 18)
                    .unwrap_or_else(|_| "[Could not calculate]".to_string())
                    .trim_end_matches('0')
            );
            println!("\n==========================");
        }
        Ok(new_txes)
    }
    /// Uses the signer to submit a transaction to the network. If it fails, it tries to retrieve
    /// the transaction hash that can be used on a later run with `--resume`.
    async fn broadcast<T, U>(
        &self,
        signer: &SignerMiddleware<T, U>,
        mut legacy_or_1559: TypedTransaction,
    ) -> Result<TxHash, BroadcastError>
    where
        T: Middleware,
        U: Signer,
    {
        tracing::debug!("sending transaction: {:?}", legacy_or_1559);

        // Chains which use `eth_estimateGas` are being sent sequentially and require their gas to
        // be re-estimated right before broadcasting.
        if has_different_gas_calc(signer.signer().chain_id()) || self.skip_simulation {
            // if already set, some RPC endpoints might simply return the gas value that is already
            // set in the request and omit the estimate altogether, so we remove it here
            let _ = legacy_or_1559.gas_mut().take();

            self.estimate_gas(&mut legacy_or_1559, signer.provider()).await?;
        }

        // Signing manually so we skip `fill_transaction` and its `eth_createAccessList` request.
        let signature = signer
            .sign_transaction(
                &legacy_or_1559,
                *legacy_or_1559.from().expect("Tx should have a `from`."),
            )
            .await
            .map_err(|err| BroadcastError::Simple(err.to_string()))?;

        // Submit the raw transaction
        let pending = signer
            .provider()
            .send_raw_transaction(legacy_or_1559.rlp_signed(&signature))
            .await
            .map_err(|err| BroadcastError::Simple(err.to_string()))?;

        Ok(pending.tx_hash())
    }

    async fn estimate_gas<T>(
        &self,
        tx: &mut TypedTransaction,
        provider: &Provider<T>,
    ) -> Result<(), BroadcastError>
    where
        T: JsonRpcClient,
    {
        tx.set_gas(
            provider
                .estimate_gas(tx)
                .await
                .wrap_err_with(|| format!("Failed to estimate gas for tx: {}", tx.sighash()))
                .map_err(|err| BroadcastError::Simple(err.to_string()))? *
                self.gas_estimate_multiplier /
                100,
        );
        Ok(())
    }
}

#[derive(thiserror::Error, Debug, Clone)]
pub enum BroadcastError {
    Simple(String),
    ErrorWithTxHash(String, TxHash),
}
impl fmt::Display for BroadcastError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            BroadcastError::Simple(err) => write!(f, "{err}"),
            BroadcastError::ErrorWithTxHash(err, tx_hash) => {
                write!(f, "\nFailed to wait for transaction {tx_hash:?}:\n{err}")
            }
        }
    }
}