// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void SSNodeList_Init(struct SSNodeList *this) {
    M2C_FIELD(this, s16 *, 0) = 0;
    M2C_FIELD(this, s16 *, 2) = 0;
    M2C_FIELD(this, s32 *, 4) = 0;
    M2C_FIELD(this, s32 *, 8) = 0;
}
