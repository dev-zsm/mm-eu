#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0365.h"
s32 func_80003688(s32 a, s32 limb, u32 *dl, s32 d, s32 e, u8 *thisx) {
    if (M2C_FIELD(thisx, s32 *, 0x36C) == 2) {
        if (limb == 4 && M2C_FIELD(thisx, s16 *, 0x284) != 0xE) {
            *dl = 0;
        }
        if (limb == 6) {
            *dl = 0;
        }
    }
    return 0;
}
