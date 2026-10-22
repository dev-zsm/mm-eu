// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Math_Vec3f_DistXZ(s32, s32, s32, s32);          /* extern */

void Actor_WorldDistXZToActor(s32 arg0, s32 arg1) {
    Math_Vec3f_DistXZ(arg0 + 0x24, arg1 + 0x24, arg0, arg1);
}
