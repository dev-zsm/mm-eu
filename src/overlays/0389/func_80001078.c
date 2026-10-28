// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A983F4();                            /* extern */
extern M2C_UNK D_80A98908;

void func_80001078(u8 *arg0) {
    s16 temp_v0;
    s32 temp_v0_2;
    u8 *temp_v0_3;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x162);
    if (temp_v0 >= -0x13F) {
        M2C_FIELD(arg0, s16 *, 0x162) = (s16) (temp_v0 - 0xA);
        return;
    }
    temp_v0_2 = (s32) (M2C_FIELD(arg0, s16 *, 0x1C) & 0xF000) >> 0xC;
    if ((temp_v0_2 == 2) || (temp_v0_2 == 5)) {
        func_80A983F4();
        return;
    }
    temp_v0_3 = M2C_FIELD(arg0, u8 **, 0x124);
    M2C_FIELD(arg0, M2C_UNK **, 0x174) = &D_80A98908;
    if (temp_v0_3 != NULL) {
        M2C_FIELD(temp_v0_3, s16 *, 0x14) = 0;
    }
}
