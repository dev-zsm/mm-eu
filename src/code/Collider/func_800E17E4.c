// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Collider_InitTris(s32, s32);                    /* extern */
M2C_UNK Collider_SetTris(s32, s32, s32, s32, s32);     /* extern */

s32 Collider_InitAndSetTris(struct PlayState *play, struct ColliderTris *dest, struct Actor *actor, struct ColliderTrisInit *src, struct ColliderTrisElement *trisElements) {
    Collider_InitTris(play, dest);
    Collider_SetTris(play, dest, actor, src, trisElements);
    return 0;
}
