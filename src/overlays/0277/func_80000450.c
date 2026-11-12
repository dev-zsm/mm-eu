#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(s32, M2C_UNK, u8 *);        /* extern */
extern M2C_UNK D_809AF614;

void func_80000450(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1BC);
    if ((((M2C_FIELD(arg0, s16 *, 0x1C) & 0xF) * 0x14) + 0x14) < temp_v0) {
        func_800B8C4C(M2C_FIELD(arg0, s32 *, 0x120), 0x38B6, arg0);
        M2C_FIELD(arg0, f32 *, 0x70) = (f32) ((f32) ((s32) (M2C_FIELD(arg0, s16 *, 0x1C) & 0xF0) >> 4) + 6.0f);
        M2C_FIELD(arg0, s16 *, 0x1BC) = 0;
        M2C_FIELD(arg0, M2C_UNK **, 0x1B8) = &D_809AF614;
        M2C_FIELD(arg0, f32 *, 0x74) = -0.5f;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x1BC) = (s16) (temp_v0 + 1);
}
