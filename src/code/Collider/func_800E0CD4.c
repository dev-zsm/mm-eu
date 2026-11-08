// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Collider_InitJntSph(s32, s32);                    /* extern */
M2C_UNK Collider_SetJntSph(s32, s32, s32, s32, s32);     /* extern */

s32 Collider_InitAndSetJntSph(struct PlayState *play, struct ColliderJntSph *dest, struct Actor *actor, struct ColliderJntSphInit *src, struct ColliderJntSphElement *jntSphElements) {
    Collider_InitJntSph(play, dest);
    Collider_SetJntSph(play, dest, actor, src, jntSphElements);
    return 0;
}
