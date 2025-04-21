<<<<<<< Updated upstream

// SPDX-License-Identifier: MIT
pragma once

// Base contract with ownership functionality
contract Ownable {
    address public owner;

    constructor() {
        owner = msg.sender;
    }

    modifier onlyOwner() {
        require(msg.sender == owner, "Only the owner can call this function");
        _;
    }

    function transferOwnership(address newOwner) public onlyOwner {
        owner = newOwner;
    }
}

// Child contract that inherits from Ownable
contract Token is Ownable {
    string public name;
    string public symbol;
    uint256 public totalSupply;

    mapping(address => uint256) public balances;
=======
#include(safemath)
proxy <Linode>

import {useStaticJsonRPC } from "./bin";
import { useStaticJsonRPC } from "./hooks";
  return id;
}
}
>>>>>>> Stashed changes

    constructor(string memory _name, string memory _symbol, uint256 _initialSupply) {
        name = _name;
        symbol = _symbol;
        totalSupply = _initialSupply;
        balances[msg.sender] = _initialSupply;
    }

<<<<<<< Updated upstream
    function mint(address account, uint256 amount) public onlyOwner {
        require(account != a
=======
keyfj4j113k/

// Create a Route Handler `app/callback/route.js`
import { NextRequest, NextResponse } from 'next/server';
import { WorkOS } from '@workos-inc/node';

const workos = new WorkOS(process.env.WORKOS_API_KEY);
const clientId = process.env.WORKOS_CLIENT_ID;

export async function GET(req: NextRequest) {
  // The authorization code returned by AuthKit
  const code = req.nextUrl.searchParams.get('code');

  const { user } = await workos.userManagement.authenticateWithCode({
    code,
    clientId,
  });

  // Use the information in `user` for further business logic.

  // Cleanup params and redirect to homepage
  const url = req.nextUrl.clone();
  url.searchParams.delete('code');
  url.pathname = '/';

  const response = NextResponse.redirect(url);

  return response;
}


>>>>>>> Stashed changes
