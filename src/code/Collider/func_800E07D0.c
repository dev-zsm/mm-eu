// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

M2C_UNK Collider_InitElement(s32, s32);                    /* extern */
M2C_UNK Collider_InitJntSphElementDim(s32, s32);                    /* extern */

s32 Collider_InitJntSphElement(struct PlayState *play, struct ColliderJntSphElement *jntSphElem) {
    Collider_InitElement(play, jntSphElem);
    Collider_InitJntSphElementDim(play, (u8 *)jntSphElem + 0x28);
    return 1;
}
