// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B70A4(u8 *, M2C_UNK, s32);            /* extern */
s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_80151DF4(s32, M2C_UNK, u8 *);        /* extern */
extern M2C_UNK D_80986DC0;

void func_800000CC(u8 *arg0, s32 arg1) {
    if (func_800B8254(arg0, arg1) != 0) {
        func_80151DF4(arg1, 0x277B, arg0);
        M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80986DC0;
        return;
    }
    if ((M2C_FIELD(arg0, f32 *, 0x98) < 60.0f) && (func_800B70A4(arg0, 0x3000, arg1) != 0)) {
        func_800B8398(arg0, arg1, 0x42DC0000);
    }
}
