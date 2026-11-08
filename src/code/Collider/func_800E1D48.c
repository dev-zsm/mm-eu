// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Collider_InitQuad(s32, s32);                    /* extern */
M2C_UNK Collider_SetQuad(s32, s32, s32, s32);          /* extern */

s32 Collider_InitAndSetQuad(struct PlayState *play, struct ColliderQuad *dest, struct Actor *actor, struct ColliderQuadInit *src) {
    Collider_InitQuad(play, dest);
    Collider_SetQuad(play, dest, actor, src);
    return 0;
}
