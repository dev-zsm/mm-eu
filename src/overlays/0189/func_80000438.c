// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFCBC(s32, s16, M2C_UNK, M2C_UNK, s32); /* extern */

void func_80000438(u8 *arg0, u8 *arg1) {
    s16 temp_v1;
    u8 *temp_v0;

    temp_v1 = M2C_FIELD(arg1, s16 *, 0xA4);
    temp_v0 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    if (temp_v1 == 0x34) {
        M2C_FIELD(temp_v0, f32 *, 0x24) = -50.0f;
        M2C_FIELD(temp_v0, f32 *, 0x2C) = 155.0f;
    } else if (temp_v1 == 0x29) {
        M2C_FIELD(temp_v0, f32 *, 0x24) = 60.0f;
        M2C_FIELD(temp_v0, f32 *, 0x2C) = -190.0f;
    }
    func_800FFCBC(temp_v0 + 0xBE, (s16) (M2C_FIELD(arg0, s16 *, 0x92) + 0x8000), 5, 0x3E8, 0);
}
