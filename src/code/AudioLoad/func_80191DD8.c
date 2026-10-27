// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801F84B0;

void func_80191DD8(void) {
    M2C_FIELD(&D_801F84B0, s32 *, 0x1D84) = 0;
    M2C_FIELD(&D_801F84B0, s32 *, 0x1DE8) = 0;
}
