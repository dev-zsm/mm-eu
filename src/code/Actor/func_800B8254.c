// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

s32 Actor_TalkOfferAccepted(struct Actor *actor, struct GameState *gameState) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(actor, s32 *, 4);
    if (temp_v1 & 0x100) {
        M2C_FIELD(actor, s32 *, 4) = (s32) (temp_v1 & ~0x100);
        return 1;
    }
    return 0;
}
