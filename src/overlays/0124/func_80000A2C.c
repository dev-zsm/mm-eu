#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_808E3B28;

void func_80000A2C(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;
    u16 temp_v1;
    s16 temp_v1_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x24A);
    if (temp_v0 != 0) {
        temp_v1 = M2C_FIELD(arg0, u16 *, 0x90);
        M2C_FIELD(arg0, s16 *, 0x24A) = (s16) (temp_v0 - 1);
        if (temp_v1 & 1) {
            M2C_FIELD(arg0, u16 *, 0x90) = (u16) (temp_v1 & 0xFFFE);
            M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
        }
    } else {
        temp_v1_2 = M2C_FIELD(arg0, u16 *, 0x90);
        if (temp_v1_2 & 1) {
            M2C_FIELD(arg0, u16 *, 0x90) = (u16) (M2C_FIELD(arg0, u16 *, 0x90) & 0xFFFE);
            M2C_FIELD(arg0, M2C_UNK **, 0x1F4) = &D_808E3B28;
            M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
        }
    }
}
