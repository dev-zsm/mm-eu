// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void func_8018902C(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_FIELD(arg0, s32 *, 0) = (s32) ((((arg2 >> 4) & 0xFF) << 0x10) | 0x15000000 | (arg1 & 0xFFFF));
    M2C_FIELD(arg0, s32 *, 4) = arg3;
}
