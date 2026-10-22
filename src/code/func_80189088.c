// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void func_80189088(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0) = (s32) (((arg1 & 0xFF) << 0x10) | 0x17000000);
    M2C_FIELD(arg0, s32 *, 4) = arg2;
}
