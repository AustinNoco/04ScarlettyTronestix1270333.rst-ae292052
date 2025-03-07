Tronestix AGI __coral/xyz__ Vercel.com
path: 
          - cmd: cd tests/declare-id && anchor test --skip-lint && npx tsc --noEmit
            path: tests/declare-id
            - cmd: cd tests/declare-program && anchor test --skip-lint && npx tsc --noEmit
            path: tests/declare-program
              - cmd: cd tests/typescript && anchor test --skip-lint && npx tsc --noEmit
          # zero-copy tests cause `/usr/bin/ld: final link failed: No space left on device`
