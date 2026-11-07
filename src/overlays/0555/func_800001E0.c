#include "types.h"
#include "m2c_compat.h"
s32 func_80BA4B50(u8 *a, u8 *b, s32 c, s32 d);

s32 func_800001E0(u8 *a, u8 *play) {
    s32 r;

    if (M2C_FIELD(a, u8 *, 0x1DC) == 2) {
        r = func_80BA4B50(a, play, 4, 0x202);
    } else {
        r = M2C_FIELD(play, s32 *, 0x1CCC);
    }
    return r;
}
