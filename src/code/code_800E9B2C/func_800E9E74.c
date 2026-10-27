// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void func_800E9E74(s32 arg0, void *arg1) {
    M2C_FIELD(arg1, s8 *, 8) = 1;
    M2C_FIELD(arg1, s32 *, 0x24) = 0;
}
