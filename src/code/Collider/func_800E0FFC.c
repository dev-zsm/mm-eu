// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Collider_SetBaseToActor(s32, s32, s32);               /* extern */
M2C_UNK Collider_SetElement(s32, s32, s32);               /* extern */
M2C_UNK Collider_SetCylinderDim(s32, s32, s32);               /* extern */

s32 Collider_SetCylinderToActor(struct PlayState *play, struct ColliderCylinder *dest, struct ColliderCylinderInitToActor *src) {
    Collider_SetBaseToActor(play, dest, src);
    Collider_SetElement(play, (u8 *)dest + 0x18, (u8 *)src + 8);
    Collider_SetCylinderDim(play, (u8 *)dest + 0x40, (u8 *)src + 0x20);
    return 1;
}
