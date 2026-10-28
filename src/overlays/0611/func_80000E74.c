// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B87A0(u8 *, s32, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_80147CC4(s32);                         /* extern */
M2C_UNK func_80BE0AF4(u8 *, s32);                 /* extern */
s32 func_80BE0C10(u8 *, s32);                     /* extern */
extern M2C_UNK D_80BE1010;

void func_80000E74(u8 *arg0, s32 arg1) {
    func_80BE0AF4(arg0, arg1);
    if (func_80BE0C10(arg0, arg1) == 0) {
        func_80147CC4(arg1);
        func_800B87A0(arg0, arg1, 0xC, 0x44FA0000, 1000.0f);
        M2C_FIELD(arg0, M2C_UNK **, 0x430) = &D_80BE1010;
    }
}
