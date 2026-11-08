// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void Actor_Kill(struct Actor *actor) {
    M2C_FIELD(actor, s32 *, 0x13C) = 0;
    M2C_FIELD(actor, s32 *, 0x138) = 0;
    M2C_FIELD(actor, s32 *, 4) = (s32) (M2C_FIELD(actor, s32 *, 4) & ~1);
}
