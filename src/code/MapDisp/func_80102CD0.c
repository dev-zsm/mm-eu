// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801BF708;

void func_80102CD0(s32 arg0) {
    M2C_FIELD(&D_801BF708, s32 *, 0x20) = (s32) (M2C_FIELD(&D_801BF708, s32 *, 0x20) & ~arg0);
}
