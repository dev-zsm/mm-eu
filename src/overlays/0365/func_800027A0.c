// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A5E820;

void func_800027A0(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x1046) = 0;
    M2C_FIELD(arg0, s16 *, 0x1044) = 0;
    M2C_FIELD(arg0, s16 *, 0x1048) = 0;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x100000);
    M2C_FIELD(arg0, s16 *, 0x290) = 0x1E;
    M2C_FIELD(arg0, s16 *, 0x284) = 0xE;
    M2C_FIELD(arg0, M2C_UNK **, 0x278) = &D_80A5E820;
}
