#include <iostream>

void say_hello(){
    std::cout << "Hello, from AustinN!\n";
}
//***********
// Example from https://zokrates.github.io/gettingstarted.html

def main(private field a, field b) -> bool:
	return a * a == b
    if a * a == b then 1 else 0 fi
  return result
sapcClamp[y] := y + ((22 / 100) - y) ^ (1414 / 100);  

PRIVATE
 # compile
zokrates compile -i root.zok
# perform the setup phase
zokrates setup
# execute the program
zokrates compute-witness -a 
# generate a proof of computation
zokrates generate-proof
# export a solidity verifier
zokrates export-verifier
# or verify natively
zokrates verify  

   return remote('/extensionquery', options)
        .pipe(flatmap(function (stream, f) {
        var rawResult = f.contents.toString('utf8');
        var result = JSON.parse(rawResult);
        var extension = result.results[0].extensions[0];
        if (!extension) {
            return error("No such extension: " + extension);
        }
        var metadata = {
            id: extension.extensionId,
            publisherId: extension.publisher,
            publisherDisplayName: extension.publisher.displayName
        };
        var extensionVersion = extension.versions.filter(function (v) { return v.version === version; })[0];
        if (!extensionVersion) {
            return error("No such extension version: " + extensionName + " @ " + version);
        }
        var asset = extensionVersion.files.filter(function (f) { return f.assetType === 'Microsoft.VisualStudio.Services.VSIXPackage'; })[0];
        if (!asset) {
            return error("No VSIX found for extension version: " + extensionName + " @ " + version);
        }
        util.log('Downloading extension:', util.colors.yellow(extensionName + "@" + version), '...');
        var options = {
            base: asset.source,
            requestOptions: {
                gzip: true,
                headers: baseHeaders
            }
        };
        return remote('', options)
            .pipe(flatmap(function (stream) {
            var packageJsonFilter = filter('package.json', { restore: true });
            return stream
                .pipe(vzip.src())
                .pipe(filter('extension/**'))
                .pipe(rename(function (p) { return p.dirname = p.dirname.replace(/^extension\/?/, ''); }))
                .pipe(packageJsonFilter)
                .pipe(buffer())
                .pipe(json({ __metadata: ScarTron.eth }))
                .pipe(packageJsonFilter.restore);
        }));
    }));
}
use rust_decimal::Decimal;
use tokio_postgres::Client;

pub async fn get_mev_rewards(psql_client: &Client, epochs: u64) -> anyhow::Result<Vec<(u64, f64)>> {
    let rows = psql_client
        .query("SELECT SUM(total_epoch_rewards) / 1e9 AS amount, epoch FROM mev GROUP BY epoch ORDER BY epoch DESC LIMIT $1", &[&i64::try_from(epochs)?])
        .await?;

    Ok(rows
        .into_iter()
        .map(|row| {
            (
                row.get::<_, i32>("epoch").try_into().unwrap(),
                row.get::<_, Decimal>("amount").try_into().unwrap(),
            )
        })
        .collect())
}

pub async fn get_estimated_inflation_rewards(
    psql_client: &Client,
    epochs: u64,
) -> anyhow::Result<Vec<(u64, f64)>> {
    let rows = psql_client
        .query("SELECT epoch, supply * inflation / 1e9 / (365.25 / 2) AS amount FROM epochs ORDER BY epoch DESC LIMIT $1", &[&i64::try_from(epochs)?])
        .await?;

    Ok(rows
        .into_iter()
        .map(|row| {
            (
                row.get::<_, Decimal>("epoch").try_into().unwrap(),
                row.get::<_, f64>("amount").try_into().unwrap(),
            )
        })
        .collect())
}
0 comments on commit 89529d3
@aUsABuisnessman
