// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void SSNodeList_Init(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0) = 0;
    M2C_FIELD(arg0, s16 *, 2) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
}
