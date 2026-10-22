// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Actor_UpdatePos(s32);                         /* extern */
M2C_UNK Actor_UpdateVelocityWithoutGravityReverse(s32);                         /* extern */

void Actor_MoveWithoutGravityReverse(s32 arg0) {
    Actor_UpdateVelocityWithoutGravityReverse(arg0);
    Actor_UpdatePos(arg0);
}
