// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Math_Vec3f_Yaw(s32, s32, s32, s32);          /* extern */

s16 Actor_FocusYawTowardActor(struct Actor *actorA, struct Actor *actorB) {
    Math_Vec3f_Yaw((u8 *)actorA + 0x3C, (u8 *)actorB + 0x3C, actorA, actorB);
}
