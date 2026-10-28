// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_800FEB44(s16);                             /* extern */
f32 func_800FEB84(s16);                             /* extern */
extern f32 D_8088896C;
extern f32 D_80888970;

f32 func_80000AD8(u8 *arg0, M2C_UNK arg1) {
    f32 sp1C;

    sp1C = 1.0f;
    if ((func_800FEB44(M2C_FIELD(arg0, s16 *, 0xBC)) < D_8088896C) && (func_800FEB84(M2C_FIELD(arg0, s16 *, 0xBC)) < 0.0f)) {
        sp1C = D_80888970;
    }
    return sp1C;
}
