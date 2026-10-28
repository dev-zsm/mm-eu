// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A55B80;

void func_8000073C(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s32 *, 0x174) = (s32) ((((s16) M2C_FIELD(arg0, s16 *, 0x1C) >> 0xB) & 0x1F) * 0xA);
    M2C_FIELD(arg0, f32 *, 0x164) = 180.0f;
    M2C_FIELD(arg0, f32 *, 0x160) = 180.0f;
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80A55B80;
}
