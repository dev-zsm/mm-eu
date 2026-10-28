// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B877C();                                /* extern */
M2C_UNK func_800B87A0(u8 *, s32, s32, M2C_UNK, f32); /* extern */
M2C_UNK func_80A4A424(u8 *, s32);                 /* extern */
extern s32 D_801C2A90;
extern u8 D_801C2AC8;
extern M2C_UNK D_801E6EF0;

void func_800010F0(u8 *arg0, s32 arg1) {
    s16 temp_v0;

    if (func_800B877C() != 0) {
        M2C_FIELD(arg0, s32 *, 0x120) = 0;
        func_80A4A424(arg0, arg1);
        return;
    }
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x258);
    if (temp_v0 == 0x45B) {
        if (!(M2C_FIELD(&D_801E6EF0, u8 *, 0xF02) & 8)) {
            func_800B87A0(arg0, arg1, ((u32) (M2C_FIELD(&D_801E6EF0, s32 *, 0xB8) & D_801C2A90) >> D_801C2AC8) + 8, 0x43FA0000, 100.0f);
            return;
        }
        func_800B87A0(arg0, arg1, 2, 0x43FA0000, 100.0f);
        return;
    }
    if (temp_v0 == 0x45C) {
        func_800B87A0(arg0, arg1, 2, 0x43FA0000, 100.0f);
        return;
    }
    if (!(M2C_FIELD(&D_801E6EF0, u8 *, 0xF33) & 8)) {
        func_800B87A0(arg0, arg1, 0xC, 0x43FA0000, 100.0f);
        return;
    }
    func_800B87A0(arg0, arg1, 2, 0x43FA0000, 100.0f);
}
