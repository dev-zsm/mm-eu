#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0540.h"
s32 func_800002BC(Actor *thisx, s16 b) {
    s16 d = M2C_FIELD(thisx, s16 *, 0x92) - M2C_FIELD(thisx, s16 *, 0x16);
    s32 ad;

    if (d < 0) {
        ad = -d;
    } else {
        ad = d;
    }
    if (ad < b) {
        return 1;
    }
    return 0;
}
