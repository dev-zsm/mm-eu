// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Actor_MoveWithoutGravityReverse(s32);                         /* extern */

s32 SubS_ActorPathing_MoveWithoutGravityReverse(struct PlayState *play, struct ActorPathing *actorPath) {
    Actor_MoveWithoutGravityReverse(M2C_FIELD(actorPath, s32 *, 0x48));
    return 0;
}
