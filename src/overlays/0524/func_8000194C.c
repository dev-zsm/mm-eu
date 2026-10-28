// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B78768();                            /* extern */
extern M2C_UNK D_80B79720;

void func_8000194C(u8 *arg0) {
    f32 temp_f0;

    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    if (M2C_FIELD(arg0, s16 *, 0x304) != 0) {
        temp_f0 = M2C_FIELD(arg0, f32 *, 0xC4);
        if (temp_f0 > 0.0f) {
            M2C_FIELD(arg0, f32 *, 0xC4) = (f32) (temp_f0 - 20.0f);
        }
        M2C_FIELD(arg0, f32 *, 0x68) = -1.0f;
        M2C_FIELD(arg0, f32 *, 0x78) = -1.0f;
    }
    if ((M2C_FIELD(arg0, s16 *, 0x2FC) == 1) && (M2C_FIELD(arg0, s16 *, 0x302) == 0)) {
        M2C_FIELD(arg0, s16 *, 0x2FE) = 2;
        M2C_FIELD(arg0, s16 *, 0x300) = 2;
    }
    if (M2C_FIELD(arg0, s16 *, 0x304) == 5) {
        M2C_FIELD(arg0, M2C_UNK **, 0x328) = &D_80B79720;
    }
    func_80B78768();
}
