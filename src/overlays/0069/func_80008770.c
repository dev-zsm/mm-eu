// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80134AE8(M2C_UNK *);                       /* extern */
s32 func_80137070(s32, s32);                        /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, M2C_UNK, f32, s32, f32); /* extern */
extern M2C_UNK D_600B3E0;

void func_80008770(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 pad;
    s32 sp28;
    s32 temp_a0;

    temp_a0 = arg0 + 0x1A4;
    sp28 = temp_a0;
    if (func_80137070(temp_a0, arg0) != 0) {
        func_80137788(sp28, &D_600B3E0, 0x3F800000, 0x41300000, (f32) func_80134AE8(&D_600B3E0), 2, 0.0f);
    }
}
