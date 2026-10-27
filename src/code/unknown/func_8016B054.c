// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern s32 D_801EABA0;

void func_8016B054(void *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0xA4) == 0x4F) {
        M2C_FIELD(arg0, s16 *, 0x1887A) = 0x2060;
        D_801EABA0 = -7;
    }
}
