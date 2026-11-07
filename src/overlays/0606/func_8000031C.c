#include "types.h"
#include "m2c_compat.h"
s32 func_80BD5EF0(u8 *a, u8 *b, s32 c, s32 d);

s32 func_8000031C(u8 *a, u8 *play) {
    s32 r;

    if (M2C_FIELD(a, u8 *, 0x298) == 3) {
        r = func_80BD5EF0(a, play, 4, 0x202);
    } else {
        r = M2C_FIELD(play, s32 *, 0x1CCC);
    }
    return r;
}
