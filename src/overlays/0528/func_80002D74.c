// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B70A4(u8 *, M2C_UNK, s32);            /* extern */
s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_80B7B90C(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80B7BCD0(u8 *);                      /* extern */
M2C_UNK func_80B7DF04(u8 *, s32);                 /* extern */
extern M2C_UNK D_80B7DF88;

void func_80002D74(u8 *arg0, s32 arg1) {
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x2F8) = &D_80B7DF88;
        func_80B7DF04(arg0, arg1);
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
        func_80B7B90C(arg0, 0, 0);
        return;
    }
    if ((func_800B70A4(arg0, 0x3000, arg1) != 0) && (M2C_FIELD(arg0, f32 *, 0x98) < 100.0f)) {
        func_800B8398(arg0, arg1, 0x42F00000);
    }
    M2C_FIELD(arg0, f32 *, 0x70) = 1.5f;
    func_80B7BCD0(arg0);
}
