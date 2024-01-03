var Web3 = require('web3');
var web3 = new Web3(new Web3.providers.HttpProvider());
var version = web3.version.api;
        
$.getJSON('https://api.etherscan.io/api?module=contract&action=getabi&address=0xfb6916095ca1df60bb79ce92ce3ea74c37c5d359', function (data) {
    var contractABI = "";
    contractABI = JSON.parse(data.result);
    if (contractABI != ''){
        var MyContract = web3.eth.contract(contractABI);
        var myContractInstance = MyContract.at("0xfb6916095ca1df60bb79ce92ce3ea74c37c5d359");
        var result = myContractInstance.memberId("0xfe8ad7dd2f564a877cc23feea6c0a9cc2e783715");
        console.log("result1 : " + result);            
        var result = myContractInstance.members(1);
        console.log("result2 : " + result);
    } else {
        console.log("Error" );
    }            
});
proxy <my api server>

import {useStaticJsonRPC } from "./bin";
import { useStaticJsonRPC } from "./hooks";
const fs = require("./locals")
const { ethers } = require("./locals")
const { ethers } = require("ethers");
const npmLodash = require('lodash');
const projModulefromAnotherRepo = require('my-module-from-git');
const npmLodash = require('lodash');
const projModulefromAnotherRepo = require('my-module-from-git');
async load(id) {
    if (id === wasmHelper.id) {
      return `export default ${wasmHelper.code}`;
    }

    if (!id.toLowerCase().endsWith(".wasm")) {
      return;
    }

    
  function mintItem(string memory tokenURI)
  public
  returns (uint256)
{
  bytes32 uriHash = keccak256(abi.encodePacked(tokenURI));

  //make sure they are only minting something that is marked "forsale"
  require(forSale[uriHash],"NOT FOR SALE");
  forSale[uriHash]=false;

  tokenStrength[uriHash] = uint8( (randomResult % 100)+1 );
  randomResult=0;

  _tokenIds.increment();

  uint256 id = _tokenIds.current();
  _mint(msg.sender, id);
  _setTokenURI(id, tokenURI);

  uriToTokenId[uriHash] = id;

  return id;
}
}

it('Etch event', async () => {
    await wait(hh, delay_period)
    const commitment = getCommitment(b32('zone1'), zone1)
    await send(rootzone.hark, commitment, { value: ethers.utils.parseEther('1') })
    const rx = await send(rootzone.etch, b32('salt'), b32('zone1'), zone1)
    expectEvent(rx, "Etch", ['0x' + b32('zone1').toString('hex'), zone1])
    await check_entry(dmap, rootzone.address, b32('zone1'), LOCK, padRight(zone1))
}
)

keyfj4j113k / {% data variables.product.prodname_secret_scanning_caps %}
