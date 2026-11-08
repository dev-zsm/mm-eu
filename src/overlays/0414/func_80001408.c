#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0414.h"
s32 func_80001408(s32 a, s32 limb, s32 *dl, s32 d, s32 e, u8 *thisx) {
    if (M2C_FIELD(thisx, s16 *, 0x216) < 0) {
        if (limb == 9) {
            *dl = 0;
        }
    } else if (limb == 1) {
        *dl = 0;
    }
    return 0;
}
