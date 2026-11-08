#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0489.h"
s32 func_800001D0(u8 *a) {
    s32 i;
    s32 n = M2C_FIELD(a, s8 *, 0x308) - 1;

    for (i = 0; i < n; i++) {
        if (M2C_FIELD(a, f32 *, 0x320) < ((f32 *)(a + 0x37C))[i]) {
            break;
        }
    }
    return i;
}
