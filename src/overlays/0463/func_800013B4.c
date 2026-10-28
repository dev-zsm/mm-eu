// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801378E0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_60058CC;
extern M2C_UNK D_80AFCC2C;

void func_800013B4(u8 *arg0) {
    func_801378E0(arg0 + 0x144, &D_60058CC, arg0);
    M2C_FIELD(arg0, s16 *, 0x28C) = 0x3C;
    M2C_FIELD(arg0, M2C_UNK **, 0x280) = &D_80AFCC2C;
}
