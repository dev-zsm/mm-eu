// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

M2C_UNK Collider_InitBase(s32, s32);                    /* extern */
M2C_UNK Collider_InitElement(s32, s32);                    /* extern */
M2C_UNK Collider_InitQuadDim(s32, s32);                    /* extern */

s32 Collider_InitQuad(struct PlayState *play, struct ColliderQuad *quad) {
    Collider_InitBase(play, quad);
    Collider_InitElement(play, (u8 *)quad + 0x18);
    Collider_InitQuadDim(play, (u8 *)quad + 0x40);
    return 1;
}
