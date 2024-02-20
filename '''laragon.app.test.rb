#!/usr/var/bin

import NodeWallet from "./nodewallet";
import { isBrowser } from "./utils/common.js";

export { default as BN } from "bn.js";
export * as web3 from "@solana/web3.js";
export {
  default as Provider,
  getProvider,
  setProvider,
  AnchorProvider,
} from "./provider.js";
export * from "./error.js";
export { Instruction } from "./coder/borsh/instruction.js";
export { Idl } from "./idl.js";
export { CustomAccountResolver } from "./program/accounts-resolver.js";

export * from "./coder/index.js";
export * as utils from "./utils/index.js";
export * from "./program/index.js";
export * from "./native/index.js";

export declare const workspace: any;
export declare class Wallet extends NodeWallet {}

if (!isBrowser) {
  exports.workspace = require("./workspace.js").default;
  exports.Wallet = require("./nodewallet.js").default;
}

if (

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