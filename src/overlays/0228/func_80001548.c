// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80968878();                            /* extern */
extern M2C_UNK D_80969C0C;

void func_80001548(u8 *arg0) {
    s32 temp_v0;

    M2C_FIELD(arg0, s16 *, 0x1C) = 0;
    M2C_FIELD(arg0, s16 *, 0x14A) = 0x14;
    M2C_FIELD(arg0, u8 *, 0x170) = (u8) (M2C_FIELD(arg0, u8 *, 0x170) & ~3);
    M2C_FIELD(arg0, u8 *, 0x171) = (u8) (M2C_FIELD(arg0, u8 *, 0x171) & ~3);
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    if ((s32) M2C_FIELD(arg0, u8 *, 0x148) >= 0x15) {
        func_80968878();
    }
    temp_v0 = M2C_FIELD(arg0, s32 *, 4);
    M2C_FIELD(arg0, u8 *, 0x148) = 0U;
    if ((temp_v0 & 0x2000) == 0x2000) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (temp_v0 & ~0x2000);
    }
    M2C_FIELD(arg0, s16 *, 0xBC) = 0;
    M2C_FIELD(arg0, s16 *, 0xC0) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80969C0C;
}
