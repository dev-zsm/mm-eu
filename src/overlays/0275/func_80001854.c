// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B877C();                                /* extern */
M2C_UNK func_800B87A0(u8 *, u8 *, s32, M2C_UNK, f32); /* extern */
extern s32 D_801C2A80;
extern u8 D_801C2AC4;
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_809ACBE4;

void func_80001854(u8 *arg0, u8 *arg1) {
    u8 *sp24;
    u32 temp_v0;

    sp24 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    if (func_800B877C() != 0) {
        if ((M2C_FIELD(arg0, s16 *, 0x284) == 0x407) && !(M2C_FIELD(&D_801E6EF0, u8 *, 0xF33) & 0x20)) {
            M2C_FIELD(&D_801E6EF0, u8 *, 0xF33) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF33) | 0x20);
        }
        if (((M2C_FIELD(arg0, s16 *, 0x284) == 0x405) || (M2C_FIELD(arg0, s16 *, 0x284) == 0x406)) && !(M2C_FIELD(&D_801E6EF0, u8 *, 0xF18) & 4)) {
            M2C_FIELD(&D_801E6EF0, u8 *, 0xF18) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF18) | 4);
        }
        M2C_FIELD(arg0, s32 *, 0x120) = 0;
        M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_809ACBE4;
        return;
    }
    if (M2C_FIELD(arg0, s16 *, 0x284) == 0x407) {
        temp_v0 = (u32) (M2C_FIELD(&D_801E6EF0, s32 *, 0xB8) & D_801C2A80) >> D_801C2AC4;
        if ((temp_v0 < 3U) && !(M2C_FIELD(&D_801E6EF0, u8 *, 0xF33) & 0x20)) {
            func_800B87A0(arg0, arg1, temp_v0 + 0x22, 0x43FA0000, 100.0f);
        } else {
            func_800B87A0(arg0, arg1, 5, 0x43FA0000, 100.0f);
        }
    } else if (!(M2C_FIELD(&D_801E6EF0, u8 *, 0xF18) & 4)) {
        func_800B87A0(arg0, arg1, 0xC, 0x43FA0000, 100.0f);
    } else {
        func_800B87A0(arg0, arg1, 7, 0x43FA0000, 100.0f);
    }
    M2C_FIELD(sp24, s16 *, 0xBE) = -0x8000;
    M2C_FIELD(sp24, f32 *, 0x6C) = 0.0f;
    M2C_FIELD(sp24, f32 *, 0x64) = 0.0f;
    M2C_FIELD(sp24, s16 *, 0x32) = (s16) M2C_FIELD(sp24, s16 *, 0xBE);
}
