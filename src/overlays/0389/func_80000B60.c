// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B680C();                            /* extern */
extern M2C_UNK D_80A98908;

void func_80000B60(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x15C);
    M2C_FIELD(arg0, s16 *, 0xBC) = (s16) (M2C_FIELD(arg0, s16 *, 0xBC) + temp_v0);
    if (temp_v0 >= 0xA1) {
        M2C_FIELD(arg0, s16 *, 0x15C) = (s16) (temp_v0 - 5);
    }
    M2C_FIELD(arg0, f32 *, 0x2C) = (f32) (M2C_FIELD(arg0, f32 *, 0x2C) + 4.0f);
    func_800B680C();
    if (M2C_FIELD(arg0, f32 *, 0x28) < 0.0f) {
        M2C_FIELD(arg0, M2C_UNK **, 0x174) = &D_80A98908;
    }
}
