// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void DynaPolyActor_Init(struct DynaPolyActor *dynaActor, s32 transformFlags) {
    M2C_FIELD(dynaActor, s32 *, 0x144) = -1;
    M2C_FIELD(dynaActor, f32 *, 0x148) = 0.0f;
    M2C_FIELD(dynaActor, f32 *, 0x14C) = 0.0f;
    M2C_FIELD(dynaActor, s32 *, 0x154) = transformFlags;
    M2C_FIELD(dynaActor, s8 *, 0x158) = 0;
}
