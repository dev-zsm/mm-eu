// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800C9C4C(s32, s32, s32, s32, f32 *, M2C_UNK *, M2C_UNK *); /* extern */

s32 func_8000016C(u8 *arg0, s32 arg1) {
    s32 pad;
    M2C_UNK sp30;
    f32 sp2C;
    M2C_UNK sp28;

    if ((func_800C9C4C(arg1, arg1 + 0x830, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), &sp2C, &sp30, &sp28) != 0) && (M2C_FIELD(arg0, f32 *, 0x28) < sp2C)) {
        return 1;
    }
    return 0;
}
