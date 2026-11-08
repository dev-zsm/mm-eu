// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Collider_ResetOCBase(s32, s32);                    /* extern */
M2C_UNK Collider_ResetOCElement(s32, s32);                    /* extern */

s32 Collider_ResetQuadOC(struct PlayState *play, struct Collider *col) {
    Collider_ResetOCBase(play, col);
    Collider_ResetOCElement(play, (u8 *)col + 0x18);
    return 1;
}
