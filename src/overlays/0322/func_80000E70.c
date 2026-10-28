// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B5B64(s32, s32);                    /* extern */
s32 func_800EE03C(s32, M2C_UNK);                    /* extern */
M2C_UNK func_800F1944(s8);                          /* extern */
s32 func_800F1984(s8);                              /* extern */
M2C_UNK func_800F1A08(s8, u8 *);                  /* extern */
M2C_UNK func_80112D7C(s32, M2C_UNK);                /* extern */
extern M2C_UNK D_80A1F1FC;
extern M2C_UNK D_80A1F350;

void func_80000E70(u8 *arg0, s32 arg1) {
    s16 temp_a1;

    if (func_800EE03C(arg1, 0x67) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x14C) = &D_80A1F350;
        return;
    }
    if (func_800F1984(M2C_FIELD(arg0, s8 *, 0x38)) != 0) {
        func_800F1A08(M2C_FIELD(arg0, s8 *, 0x38), arg0);
        M2C_FIELD(arg0, M2C_UNK **, 0x14C) = &D_80A1F1FC;
        func_800B5B64(arg1, (s32) (M2C_FIELD(arg0, s16 *, 0x1C) & 0xFE00) >> 9);
        if (M2C_FIELD(arg0, u16 *, 0x14A) & 2) {
            func_80112D7C(arg1, 0x40);
        }
        temp_a1 = M2C_FIELD(arg0, s16 *, 0x18);
        if (temp_a1 != 0) {
            func_800B5B64(arg1, (s32) temp_a1);
        }
    } else if (M2C_FIELD(arg0, f32 *, 0x98) < 350.0f) {
        func_800F1944(M2C_FIELD(arg0, s8 *, 0x38));
    }
}
