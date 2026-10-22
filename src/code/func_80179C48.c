// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801F3400;

void func_80179C48(void) {
    M2C_FIELD(&D_801F3400, s32 *, 0) = 0;
    M2C_FIELD(&D_801F3400, s32 *, 4) = 0;
}
