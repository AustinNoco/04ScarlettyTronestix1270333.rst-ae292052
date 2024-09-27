TheNFT/Mint_Launch

$ printf "blob 6\000hello\n" | sha1sum
$ curl https://api.github.com/repos/:owner/:repo/git/blobs/:file_sha

# Example
$ curl https://api.github.com/repos/rstallman/hello/git/blobs/ce013625030ba8dba906f756967f9e9ca394464a

const mintpNFT = async ({ data, api }) => {
  const tx = await transactionBuilder()
    .add(
      createV1(umi, {
        mint: mint,
        api,
        name: data.imgName,
        symbol: data.symbol,
        isCollection: false,
        sellerFeeBasisPoints: createAmount(data.sellerFeeBasisPoints, "%", 2),
        tokenStandard: TokenStandard.ProgrammableNonFungible,
        collection: {
          verified: false,
          key: data.collectionNFT,
        },
      })
    )
    .add(
      mintV1(umi, {
        mint: mint.publicKey,
        authority: umi.identity,
        tokenOwner: keypair.publicKey,
        tokenStandard: TokenStandard.ProgrammableNonFungible,
      })
    )
    .sendAndConfirm(umi, { send: { commitment: "finalized" } });
  const metadataAccount = findMetadataPda(umi, { mint: mint.publicKey })[0];
  await verifyCollectionV1(umi, {
    metadata: metadataAccount,
    collectionMint: publicKey(data.collectionNFT),
    authority: umi.identity,
  }).sendAndConfirm(umi, { send: { skipPreflight: true } });
  console.log("New NFT minted", mint.publicKey);
};
# IDE - VSCode
.vscode/*
!.vscode/settings.json
!.vscode/tasks.json
!.vscode/launch.json
!.vscode/extensions.json

$ misc
  sass-cache
  /connect.lock
  /coverage
  /libpeerconnection.log
  9 months ago

i can build tonight
lerna-debug.log
10 months ago

twitter
testem.log
/typings
/docs

# e2e
/e2e/*.js
/e2e/*.map

# System Files
.DS_Store
Thumbs.db

{
  "rules": {
    "color-hex-case": "lower",
    "color-no-invalid-hex": true,

    "function-calc-no-unspaced-operator": true,
    "function-comma-space-after": "always-single-line",
    "function-comma-space-before": "never",
    "function-name-case": "lower",
    "function-url-quotes": "always",
    "function-whitespace-after": "always",

    "number-leading-zero": "always",
    "number-no-trailing-zeros": true,
    "length-zero-no-unit": true,

    "string-no-newline": true,
    "string-quotes": "single",

    "unit-case": "lower",
    "unit-no-unknown": true,
    "unit-whitelist": ["px", "%", "deg", "ms", "em", "vh", "vw", "s", "rem"],

    "block-closing-brace-newline-after": [
      "always",
      {
        "ignoreAtRules": ["if", "else"]
      }                            
            "scripts": [
              "node_modules/pace-js/pace.min.js"
],
            "styles": [ em ]
              "node_modules/bootstrap/dist/css/bootstrap.css",
              "node_modules/typeface-exo/index.css",
              "node_modules/roboto-fontface/css/roboto/roboto-fontface.css",
              "node_modules/ionicons/scss/ionicons.scss",
              "node_modules/socicon/css/socicon.css",
              "node_modules/nebular-icons/scss/nebular-icons.scss",
              "node_modules/pace-js/templates/pace-theme-flash.tmpl.css",
@@ -136,12 +104,7 @@
            "assets": [
              "src/assets",
              "src/favicon.ico",
              "src/favicon.png"
            ]
          }
        },
@@ -185,11 +148,8 @@
  "defaultProject": "ngx-admin-demo",
  "schematics": {
    "@schematics/angular:component": {
      "style": "scss"
    },
    "@schematics/angular:directive": {}
  }
}