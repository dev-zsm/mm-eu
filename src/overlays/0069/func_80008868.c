// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
s32 func_80137C58(s32, f32);                        /* extern */
M2C_UNK func_801A0070(s32, M2C_UNK);                /* extern */
extern M2C_UNK D_600AD08;

void func_80008868(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 pad;
    s32 sp18;
    f32 temp_f6;
    s32 temp_a0;

    temp_f6 = (f32) func_80134AE8(&D_600AD08);
    temp_a0 = arg0 + 0x1A4;
    sp18 = temp_a0;
    if (func_80137C58(temp_a0, temp_f6 - 1.0f) != 0) {
        func_801A0070(arg0 + 0xEC, 0x282B);
    }
    func_80137070(sp18);
}
