// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

s32 Actor_HasParent(struct Actor *actor, struct PlayState *play) {
    if (M2C_FIELD(actor, s32 *, 0x120) != 0) {
        return 1;
    }
    return 0;
}
