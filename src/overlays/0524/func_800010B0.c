// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B790C0;

void func_800010B0(u8 *arg0, M2C_UNK arg1) {
    if (!(M2C_FIELD(arg0, u16 *, 0x30A) & 4)) {
        M2C_FIELD(arg0, M2C_UNK **, 0x328) = &D_80B790C0;
        M2C_FIELD(arg0, s16 *, 0x306) = -1;
    }
}
