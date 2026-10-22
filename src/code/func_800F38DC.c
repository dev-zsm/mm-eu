// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801E6EF0;

void Horse_ResetHorseData(s32 arg0) {
    M2C_FIELD(&D_801E6EF0, s16 *, 0x1000) = 0x35;
    M2C_FIELD(&D_801E6EF0, s16 *, 0x1002) = -0x58C;
    M2C_FIELD(&D_801E6EF0, s16 *, 0x1004) = 0x101;
    M2C_FIELD(&D_801E6EF0, s16 *, 0x1006) = -0x505;
    M2C_FIELD(&D_801E6EF0, s16 *, 0x1008) = 0x2AAA;
}
