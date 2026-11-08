// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void DynaPoly_InitWaterBoxList(struct DynaWaterBoxList *waterBoxList) {
    M2C_FIELD(waterBoxList, s32 *, 0) = 0;
    M2C_FIELD(waterBoxList, s32 *, 4) = 0;
}
