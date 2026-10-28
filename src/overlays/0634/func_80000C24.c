// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B877C();                                /* extern */
M2C_UNK func_800B87A0(s32, s32, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_80BF939C(s32, s32);                    /* extern */
extern M2C_UNK D_801E6EF0;

void func_80000C24(s32 arg0, s32 arg1) {
    if (func_800B877C() != 0) {
        if (!(M2C_FIELD(&D_801E6EF0, u8 *, 0xF4A) & 0x10)) {
            M2C_FIELD(&D_801E6EF0, u8 *, 0xF4A) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF4A) | 0x10);
        }
        func_80BF939C(arg0, arg1);
        return;
    }
    if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF4A) & 0x10) {
        func_800B87A0(arg0, arg1, 5, 0x43FA0000, 100.0f);
        return;
    }
    func_800B87A0(arg0, arg1, 0xC, 0x43FA0000, 100.0f);
}
