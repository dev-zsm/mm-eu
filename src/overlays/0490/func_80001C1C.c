#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0490.h"

s32 func_800B8254(u8 *, u8 *);                  /* extern */
M2C_UNK func_800B83C0(u8 *, u8 *);              /* extern */
M2C_UNK func_801A560C(u8 *, M2C_UNK);             /* extern */
s32 func_80B35584(u8 *, u8 *);                  /* extern */
M2C_UNK func_80B36140(u8 *, u8 *);              /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80B363C8;

void func_80001C1C(u8 *arg0, u8 *arg1) {
    u8 *sp24;
    u32 temp_v0;
    u16 temp_v0_2;

    sp24 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    if (M2C_FIELD(arg1, u8 *, 0x1F2C) == 0) {
        func_80B36140(arg0, arg1);
    }
    if (func_80B35584(arg0, arg1) == 0) {
        if (func_800B8254(arg0, arg1) != 0) {
            M2C_FIELD(&D_801E6EF0, u8 *, 0xF10) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF10) | 0x80);
            M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80B363C8;
        } else if ((M2C_FIELD(arg0, f32 *, 0x98) < 100.0f) || (M2C_FIELD(arg0, u8 *, 0x114) != 0)) {
            func_800B83C0(arg0, arg1);
            if (M2C_FIELD(sp24, u8 *, 0x14B) == 1) {
                M2C_FIELD(arg0, s16 *, 0x116) = 0xE74;
            } else {
                M2C_FIELD(arg0, s16 *, 0x116) = 0xE76;
            }
        }
        temp_v0 = M2C_FIELD(arg0, u16 *, 0x1E4);
        if (temp_v0 & 2) {
            temp_v0_2 = M2C_FIELD(arg1, u16 *, 0x16936);
            if ((temp_v0_2 != 1) && (temp_v0_2 != 3) && (M2C_FIELD(arg1, u8 *, 0x1F2C) == 0)) {
                func_801A560C(arg0 + 0xEC, 0x30EA);
            }
        } else {
            M2C_FIELD(arg0, u16 *, 0x1E4) = (u16) (temp_v0 | 2);
        }
    }
}
