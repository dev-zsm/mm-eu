// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern s32 D_80862240;

void func_800038AC(u8 *arg0) {
    s16 temp_v0;

    M2C_FIELD(arg0, s32 *, 0xA6C) = (s32) (M2C_FIELD(arg0, s32 *, 0xA6C) | 0x20000);
    if (!(M2C_FIELD(arg0, u8 *, 0x275) & 0x80) && (M2C_FIELD(arg0, u16 *, 0x90) & 0x200) && (D_80862240 < 0x2000)) {
        temp_v0 = M2C_FIELD(arg0, s16 *, 0x86) + 0x8000;
        M2C_FIELD(arg0, s16 *, 0xBE) = temp_v0;
        M2C_FIELD(arg0, s16 *, 0xAD4) = temp_v0;
    }
    M2C_FIELD(arg0, s16 *, 0xAD6) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
}
