// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Actor_MoveWithGravity(s32);                         /* extern */

s32 SubS_ActorPathing_MoveWithGravity(s32 arg0, void *arg1) {
    Actor_MoveWithGravity(M2C_FIELD(arg1, s32 *, 0x48));
    return 0;
}
