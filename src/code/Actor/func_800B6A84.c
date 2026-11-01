// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Math_Vec3f_Yaw(s32, s32, s32, s32);          /* extern */

void Actor_FocusYawTowardActor(s32 arg0, s32 arg1) {
    Math_Vec3f_Yaw(arg0 + 0x3C, arg1 + 0x3C, arg0, arg1);
}
