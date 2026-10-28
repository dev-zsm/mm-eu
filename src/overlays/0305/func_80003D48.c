// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80131AF8(s32, s32);                    /* extern */
M2C_UNK func_80A097D8(u8 *, s32);                 /* extern */
extern s32 D_80A0BBAC;

void func_80003D48(u8 *arg0, s32 arg1) {
    func_80131AF8(arg1, D_80A0BBAC);
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, s32), 0x1AC)(arg0, arg1);
    func_80A097D8(arg0, arg1);
}
