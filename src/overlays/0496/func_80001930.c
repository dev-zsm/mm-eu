// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B273C(s32, u8 *, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, M2C_UNK *); /* extern */
M2C_UNK func_800B5B64(s32, s16);                    /* extern */
M2C_UNK func_80B47F28(u8 *);                      /* extern */
extern M2C_UNK D_60041A0;

void func_80001930(u8 *arg0, s32 arg1) {
    s16 temp_a1;

    if ((M2C_FIELD(arg0, u16 *, 0x90) & 1) || (M2C_FIELD(arg0, f32 *, 0x88) == -32000.0f)) {
        temp_a1 = M2C_FIELD(arg0, s16 *, 0x210);
        if (temp_a1 != 0xFF) {
            func_800B5B64(arg1, temp_a1);
        }
        func_800B273C(arg1, arg0 + 0x24, 0x40C00000, 0, 1, 1, 0xF, 0x1F1, 0xA, &D_60041A0);
        func_80B47F28(arg0);
    }
}
