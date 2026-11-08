// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

M2C_UNK Collider_InitElement(s32, s32);                    /* extern */
M2C_UNK Collider_InitTrisElementDim(s32, s32);                    /* extern */

s32 Collider_InitTrisElement(struct PlayState *play, struct ColliderTrisElement *trisElem) {
    Collider_InitElement(play, trisElem);
    Collider_InitTrisElementDim(play, (u8 *)trisElem + 0x28);
    return 1;
}
