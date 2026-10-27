// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801E6EF0;

void Actor_InitHalfDaysBit(void *arg0) {
    s32 var_v0;

    var_v0 = ((s32) M2C_FIELD(&D_801E6EF0, s32 *, 0x18) % 5) * 2;
    if (((s32) M2C_FIELD(&D_801E6EF0, u16 *, 0xC) < 0x4000) || ((s32) M2C_FIELD(&D_801E6EF0, u16 *, 0xC) >= 0xC001)) {
        var_v0 += 1;
    }
    M2C_FIELD(arg0, s16 *, 0xC) = (s16) (0x200 >> var_v0);
}
