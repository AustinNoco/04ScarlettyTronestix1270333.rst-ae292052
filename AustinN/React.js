#include(safemath)
proxy <Linode>

import {useStaticJsonRPC } from "./bin";
import { useStaticJsonRPC } from "./hooks";
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


