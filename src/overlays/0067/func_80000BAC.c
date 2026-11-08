// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0067.h"

extern u8 D_80876F6C;

s32 func_80000BAC(u8 *arg0) {
    f32 f;

    if (&D_80876F6C == M2C_FIELD(arg0, u8 **, 0x2FC)) {
        f = M2C_FIELD(arg0, f32 *, 0x15C);
        if (f >= 29.0f && f <= 43.0f) {
            return 1;
        }
    }
    return 0;
}
