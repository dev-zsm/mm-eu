// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern u8 D_801E7E20;
extern M2C_UNK D_80AE2B30;
extern M2C_UNK D_80AE3144;
extern M2C_UNK D_80AE31DC;

void func_80000120(u8 *arg0) {
    if (!(D_801E7E20 & 2)) {
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80AE3144;
        M2C_FIELD(arg0, f32 *, 0xC4) = 700.0f;
        if (M2C_FIELD(arg0, s16 *, 0x1C) == 0) {
            M2C_FIELD(arg0, f32 *, 0x74) = -2.0f;
        }
        M2C_FIELD(arg0, s16 *, 0x148) = 0;
    } else {
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80AE31DC;
        M2C_FIELD(arg0, f32 *, 0xC4) = 300.0f;
        M2C_FIELD(arg0, f32 *, 0xCC) = 5.0f;
        if (M2C_FIELD(arg0, s16 *, 0x1C) == 0) {
            M2C_FIELD(arg0, f32 *, 0x74) = -2.0f;
        }
        M2C_FIELD(arg0, s16 *, 0x148) = 1;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80AE2B30;
}
