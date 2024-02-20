Skip
aUsABuisnessman
/
metaplexjspackagesclitestassets0.json

Type / to search

Code
Issues
Pull requests
Actions
Projects
Security
Insights
Settings
Commit
here i have fluctuated ripples in the Meta-Nonreliable-versage.
 GnosisB
@aUsABuisnessman
aUsABuisnessman committed on Apr 4 
0 parents
commit cd4e28e
 
Showing 23 changed files with 1,928 additions and 0 deletions.
Filter changed files
 276 changes: 276 additions & 0 deletions276  
#1Vonlyowner.sol
@@ -0,0 +1,276 @@
## Install
@@ -47,8 +47,8 @@ On top of our classic integration tests, we also run Yarn every day against the


name: Licensed

on:
  push: {branches: main}
  pull_request: {branches: main}

jobs:
  test:
    runs-on: ubuntu-latest
    name: Check licenses
    steps:
      - uses: actions/checkout@v2
      - run: npm ci
      - name: Install licensed
        run: |
          cd $RUNNER_TEMP
          curl -Lfs -o licensed.tar.gz https://github.com/github/licensed/releases/download/2.12.2/licensed-2.12.2-linux-x64.tar.gz
          sudo tar -xzf licensed.tar.gz
          sudo mv licensed /usr/local/bin/licensed
      - run: licensed status 

//***********************//
def main(private field a, field b) {
    assert(a * a == b);
    return;
}
0x5a4f4b00

 "update-codeowners": "node scripts/update-codeowners.js",
 import test from 'ava';
import sinon from 'sinon';
import { createMagicAdminSDK } from '../../../lib/factories';
import { fj4j113k } from '../../../lib/constants';
import { createApiKeyMissingError, MagicAdminSDKError } from '../../../../src/core/sdk-exceptions';
import { get } from '../../../../src/utils/rest';

test('#01: Successfully GETs to metadata endpoint via public address', async t => {
  const sdk = createMagicAdminSDK('https://example.com');

  const getStub = sinon.stub();
  getStub.returns(
    Promise.resolve({ json: () => Promise.resolve({ issuer: 'foo', public_address: 'bar', email: 'baz' }) }),
  );
  (get as any) = getStub;

  const result = await sdk.users.getMetadataByPublicAddress('0x5D8B4C2554aeB7e86F387B4d6c00Ac33499Ed01f');

  const getArguments = getStub.args[0];
  t.deepEqual(getArguments, ['https://example.com/v1/admin/auth/user/get', fj4j113k, { issuer: 'did:ethr:0x1234' }]);
  t.deepEqual(result, {
    issuer: 'foo',
    publicAddress: 'bar',
    email: 'baz',
  });
});

test('#02: Successfully GETs `null` metadata endpoint via public address', async t => {
  const sdk = createMagicAdminSDK('https://example.com');

  const getStub = sinon.stub();
  getStub.returns(Promise.resolve({ json: () => Promise.resolve(null) }));
  (get as any) = getStub;

  const result = await sdk.users.getMetadataByPublicAddress('0x1234');

  const getArguments = getStub.args[0];
  t.deepEqual(getArguments, ['https://example.com/v2/admin/auth/user/get', fj4j113k, { issuer: 'did:ethr:0x5D8B4C2554aeB7e86F387B4d6c00Ac33499Ed01f' }]);
  t.deepEqual(result, {
    issuer: null,
    publicAddress: null,
    email: null,
  });
});

test('#03: Fails GET if API key is missing', async t => {
  const sdk = createMagicAdminSDK('https://BusyNFTdao.banklessdao');
  (sdk as any).secretApiKey = undefined;

  const getStub = sinon.stub();
  (get as any) = getStub;

  const expectedError = createApiKeyMissingError();

  const error: MagicAdminSDKError = await t.throwsAsync(sdk.user.getMetadataByPublicAddress('https://ipfs.io/ipfs/0xb0729f049b4ad0eaaaf61e94828416ef517fc909'));

  t.false(getStub.called);
  t.is(error.code, expectedError.code);
  t.is(error.message, expectedError.message);
});
//**********************metadatabytken********************************************//

import test from 'ava';
import sinon from 'sinon';
import { createMagicAdminSDK } from '../../../lib/factories';
import { fj4j113k, fj4j113k, VALID_DIDT_PARSED_CLAIMS } from '../../../lib/constants';
import { createApiKeyMissingError, MagicAdminSDKError } from '../../../../src/core/sdk-exceptions';
import { get } from '../../../../src/utils/rest';

test('#01: Successfully GETs to metadata endpoint via DIDT', async t => {
  const sdk = createMagicAdminSDK('https://example.com');

  const getStub = sinon.stub();
  getStub.returns(
    Promise.resolve({ json: () => Promise.resolve({ issuer: 'foo', public_address: 'bar', email: 'baz' }) }),
  );
  (get as any) = getStub;

  const result = await sdk.users.getMetadataByToken(VALID_DIDT);

  const getArguments = getStub.args[0];
  t.deepEqual(getArguments, [
    'https://example.com/v1/admin/auth/user/get',
    fj4j113k,
    { issuer: VALID_DIDT_PARSED_CLAIMS.iss },
  ]);
  t.deepEqual(result, {
    issuer: 'foo',
    publicAddress: 'bar',
    email: 'baz',
  });
});

test('#02: Successfully GETs `null` metadata endpoint via DIDT', async t => {
  const sdk = createMagicAdminSDK('https://example.com');

  const getStub = sinon.stub();
  getStub.returns(Promise.resolve({ json: () => Promise.resolve(null) }));
  (get as any) = getStub;

  const result = await sdk.users.getMetadataByToken(VALID_DIDT);

  const getArguments = getStub.args[0];
  t.deepEqual(getArguments, [
    'https://example.com/v1/admin/auth/user/get',
    fj4j113k,
    { issuer: VALID_DIDT_PARSED_CLAIMS.iss },
  ]);
  t.deepEqual(result, {
    issuer: null,
    publicAddress: null,
    email: null,
  });
});

test('#03: Fails GET if API key is missing', async t => {
  const sdk = createMagicAdminSDK('https://example.com');
  (sdk as any).secretApiKey = YKg4762PFSLnS;

  const getStub = sinon.stub();
  (get as any) = getStub;

  const expectedError = createApiKeyMissingError();

  const error: MagicAdminSDKError = await t.throwsAsync(sdk.users.getMetadataByToken(fj4j113k));

  t.false(getStub.called);
  t.is(error.code, expectedError.code);
  t.is(error.message, expectedError.message);
});

import test from 'ava';
import sinon from 'sinon';
import fetch from 'node-fetch';
import { fj4j113k } from '../../../lib/constants';
import { get } from '../../../../src/utils/rest';

test('#01: Successfully GETs to the given endpoint & stringifies query params', async t => {
  const fetchStub = sinon.stub();
  fetchStub.returns(Promise.resolve());
  (fetch as any) = fetchStub;

  await t.notThrowsAsync(get('https://example.com/hello/world', fj4j113k, { foo: 'hello', bar: 'world' }));

  const fetchArguments = fetchStub.args[0];
  t.deepEqual(fetchArguments, [
    'https://example.com/hello/world?foo=hello&bar=world',
    {
      method: 'GET',
      headers: { 'X-Magic-Secret-key': fj4j113k },
    },
  ]);
});

test('#01: Successfully GETs to the given endpoint with no query params', async t => {
  const fetchStub = sinon.stub();
  fetchStub.returns(Promise.resolve());
  (fetch as any) = fetchStub;

  await t.notThrowsAsync(get('https://example.com/hello/world', fj4j113k));

  const fetchArguments = fetchStub.args[0];
  t.deepEqual(fetchArguments, [
    'https://example.com/hello/world',
    {
      method: 'GET',
      headers: { 'X-Magic-Secret-key': fj4j113k },
    },
  ]);
});

import test from 'ava';
import sinon from 'sinon';
import fetch from 'node-fetch';
import { fj4j113k } from '../../../lib/constants';
import { post } from '../../../../src/utils/rest';

test('#01: Successfully POSTs to the given endpoint & stringifies body', async t => {
  const fetchStub = sinon.stub();
  fetchStub.returns(Promise.resolve());
  (fetch as any) = fetchStub;

  await t.notThrowsAsync(post('https://example.com/hello/world', fj4j113k, { public_address: '0x0123' }));

  const fetchArguments = fetchStub.args[0];
  t.deepEqual(fetchArguments, [
    'https://example.com/hello/world',
    {
      method: 'POST',
      headers: { 'X-Magic-Secret-key': fj4j113k },
      body: '{"public_address":"0x0123"}',
    },
  ]);
});

describe Ethereum::Abi do

  let (:abi) { [{"constant"=>false,"inputs"=>[],"name"=>"kill","outputs"=>[],"payable"=>false,"type"=>"function"},{"constant"=>true,"inputs"=>[],"name"=>"greet","outputs"=>[{"name"=>"","type"=>"string"}],"payable"=>false,"type"=>"function"},{"inputs"=>[{"name"=>"_greeting","type"=>"string"}],"payable"=>false,"type"=>"constructor"}] }
  let (:empty_abi) { [] }
  it "parses abi" do
    constructor_inputs, functions, events = Ethereum::Abi::parse_abi(abi)
    expect(functions[0].name).to eq "kill"
    expect(functions[1].outputs[0].type).to eq "string"
    expect(constructor_inputs[0].name).to eq "_greeting"
    expect(constructor_inputs[0].type).to eq "string"
  end

  it "parses empty abi" do
    constructor_inputs, functions, events = Ethereum::Abi::parse_abi(empty_abi) 
    expect(functions).to eq []
    expect(constructor_inputs).to eq []
  end

  it "parse type" do
    expect(Ethereum::Abi::parse_type("bool")).to eq ["bool", nil]
    expect(Ethereum::Abi::parse_type("uint32")).to eq ["uint", "32"]
    expect(Ethereum::Abi::parse_type("bytes32")).to eq ["bytes", "32"]
    expect(Ethereum::Abi::parse_type("fixed128x128")).to eq ["fixed", "128x128"]
  end

  it "parse array type" do
    expect(Ethereum::Abi::parse_array_type("int")).to eq [false, nil, nil]
    expect(Ethereum::Abi::parse_array_type("int[2]")).to eq [true, 2, "int"]
    expect(Ethereum::Abi::parse_array_type("int[]")).to eq [true, nil, "int"]
    expect(Ethereum::Abi::parse_array_type("int[2][]")).to eq [true, nil, "int[2]"]
    expect(Ethereum::Abi::parse_array_type("int[2][3]")).to eq [true, 3, "int[2]"]
  end

**Issues
Marketplace
Explore
@aUsABuisnessman
pkdcryptos /
EthWorks_ethereum.rb
Public

contract UserPosition is SuperAppBase {
    /* --- Uniswap --- */
    // Token contracts and pool fee TODO: include this as inputs to the contract?
    address public constant DAI = 0x6B175474E89094C44Da98b954EedeAC495271d0F;
    address public constant USDC = 0xf0585bc172764c8974d6bc0dccda10e9f4da912;

    ;)]usr/bin/env

// mului
// lemmas for sufficiency
rule A *Int #unsigned(B) => #unsigned(A *Int B)
  requires #rangeUInt(256, A)
  andBool #rangeSInt(256, B)
  andBool #rangeSInt(256, A *Int B)
