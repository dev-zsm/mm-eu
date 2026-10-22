// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void func_800B61EC(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x1E95) = 0;
}
