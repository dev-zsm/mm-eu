// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B5BA4(s32, s32);                    /* extern */
M2C_UNK func_800F1944(s8);                          /* extern */
s32 func_800F1984(s8);                              /* extern */
M2C_UNK func_800F1A08(s8, u8 *);                  /* extern */
M2C_UNK func_80112D7C(s32, M2C_UNK);                /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80A1EFC4;

void func_80000CE8(u8 *arg0, s32 arg1) {
    if (func_800F1984(M2C_FIELD(arg0, s8 *, 0x38)) != 0) {
        func_800F1A08(M2C_FIELD(arg0, s8 *, 0x38), arg0);
        M2C_FIELD(arg0, M2C_UNK **, 0x14C) = &D_80A1EFC4;
        func_800B5BA4(arg1, (s32) (M2C_FIELD(arg0, s16 *, 0x1C) & 0xFE00) >> 9);
        if (M2C_FIELD(arg0, u16 *, 0x14A) & 2) {
            func_80112D7C(arg1, 0x40);
        }
        if (M2C_FIELD(arg0, u16 *, 0x14A) & 4) {
            M2C_FIELD(&D_801E6EF0, u8 *, 0xF0F) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF0F) | 2);
        }
        if (M2C_FIELD(arg0, u16 *, 0x14A) & 0x10) {
            func_80112D7C(arg1, 0x10);
        }
        M2C_FIELD(arg0, u16 *, 0x14A) = (u16) (M2C_FIELD(arg0, u16 *, 0x14A) & 0xFFF7);
        return;
    }
    if (M2C_FIELD(arg0, f32 *, 0x98) < 350.0f) {
        func_800F1944(M2C_FIELD(arg0, s8 *, 0x38));
    }
}
