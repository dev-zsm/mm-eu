// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

M2C_UNK Actor_UpdatePos(s32);                         /* extern */
M2C_UNK Actor_UpdateVelocityWithoutGravity(s32);                         /* extern */

void Actor_MoveWithoutGravity(struct Actor *actor) {
    Actor_UpdateVelocityWithoutGravity(actor);
    Actor_UpdatePos(actor);
}
