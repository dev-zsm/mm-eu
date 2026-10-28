// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8AD4(u8 *, M2C_UNK, M2C_UNK, s16, f32, s32); /* extern */
s16 func_80181190(f32, f32);                        /* extern */
M2C_UNK func_80B9DF74(u8 *, u8 *);              /* extern */
extern u8 *D_80B9E4CC;

void func_80000D68(u8 *arg0, u8 *arg1) {
    u8 temp_v0_2;
    u8 temp_v1;
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    if (M2C_FIELD(temp_v0, f32 *, 0x28) > 350.0f) {
        temp_v1 = M2C_FIELD(arg0, u8 *, 0x270);
        if (temp_v1 & 2) {
            M2C_FIELD(arg0, u8 *, 0x270) = (u8) (temp_v1 & 0xFFFD);
            func_800B8AD4(arg1, 0, 0x40400000, func_80181190(-M2C_FIELD(temp_v0, f32 *, 0x2C), -M2C_FIELD(temp_v0, f32 *, 0x24)), 5.0f, 0);
        }
    }
    temp_v0_2 = M2C_FIELD(arg0, u8 *, 0x2BD);
    if (temp_v0_2 & 2) {
        M2C_FIELD(arg0, u8 *, 0x2BD) = (u8) (temp_v0_2 & 0xFFFD);
        if (M2C_FIELD(arg0, s16 *, 0x20A) == 0) {
            M2C_FIELD(arg0, s16 *, 0x20A) = 0xF;
            M2C_FIELD(arg0, s16 *, 0x20C) = 0xF;
            func_80B9DF74(arg0, arg1);
            M2C_FIELD(D_80B9E4CC, s16 *, 0x324) = 0x14;
        }
    }
}
