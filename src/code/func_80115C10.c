// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801E6EF0;

void func_80115C10(s16 arg0) {
    M2C_FIELD(&D_801E6EF0, s16 *, 0x1018) = (s16) (M2C_FIELD(&D_801E6EF0, s16 *, 0x1018) + arg0);
}
