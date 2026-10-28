// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80875030;
extern M2C_UNK D_8087508C;

void func_800010B8(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x18E) = 0;
    M2C_FIELD(arg0, s32 *, 0x13C) = 0;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    if (M2C_FIELD(arg0, s16 *, 0x1C) == 1) {
        M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80875030;
        return;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_8087508C;
}
