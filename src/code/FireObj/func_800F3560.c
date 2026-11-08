// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Collider_DestroyCylinder(s32, s32);                    /* extern */
M2C_UNK FireObj_DestroyLight(s32, s32);                    /* extern */

void FireObj_Destroy(struct PlayState *play, struct FireObj *fire) {
    Collider_DestroyCylinder(play, (u8 *)fire + 0x2C);
    FireObj_DestroyLight(play, (u8 *)fire + 0x78);
}
