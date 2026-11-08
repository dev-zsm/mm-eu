#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0310.h"
s32 func_80000A60(s32 a, s32 limb, u32 *dl, s32 d, s32 e, u8 *thisx) {
    if (limb == 7 || limb == 8) {
        *dl = 0;
    }
    if (M2C_FIELD(thisx, u8 *, 0xB7) == 0) {
        if (limb == 5 || limb == 9) {
            *dl = 0;
        }
    }
    return 0;
}
