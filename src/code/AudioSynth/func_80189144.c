// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void func_80189144(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_FIELD(arg0, s32 *, 0) = (s32) (((arg1 & 0xFF) << 0x10) | 0x07000000 | (arg2 & 0xFFFF));
    M2C_FIELD(arg0, s32 *, 4) = arg3;
}
