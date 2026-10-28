// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80AF4BEC;

void func_800000FC(u8 *arg0) {
    if (!(M2C_FIELD(&D_801E6EF0, u8 *, 0xF2E) & 0x20)) {
        M2C_FIELD(&D_801E6EF0, u8 *, 0xF2E) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF2E) | 0x20);
        M2C_FIELD(arg0, s16 *, 0x26E) = 0x14D0;
    } else {
        M2C_FIELD(arg0, s16 *, 0x26E) = 0x14D1;
    }
    M2C_FIELD(arg0, s16 *, 0x288) = 0x1E;
    M2C_FIELD(arg0, M2C_UNK **, 0x218) = &D_80AF4BEC;
}
