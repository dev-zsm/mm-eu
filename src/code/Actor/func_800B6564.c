// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void Actor_SetScale(struct Actor *actor, f32 scale) {
    M2C_FIELD(actor, f32 *, 0x60) = scale;
    M2C_FIELD(actor, f32 *, 0x5C) = scale;
    M2C_FIELD(actor, f32 *, 0x58) = scale;
}
