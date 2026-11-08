// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Collider_ResetATBase(s32, s32);                    /* extern */
M2C_UNK Collider_ResetATElement(s32, s32);                    /* extern */
M2C_UNK Collider_ResetQuadACDist(s32, s32);                    /* extern */

s32 Collider_ResetQuadAT(struct PlayState *play, struct Collider *col) {
    Collider_ResetATBase(play, col);
    Collider_ResetATElement(play, (u8 *)col + 0x18);
    Collider_ResetQuadACDist(play, (u8 *)col + 0x40);
    return 1;
}
