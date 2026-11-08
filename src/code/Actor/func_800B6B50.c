// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

M2C_UNK Math_Vec3f_DistXYZ(s32, s32, s32, s32);          /* extern */

f32 Actor_WorldDistXYZToActor(struct Actor *actorA, struct Actor *actorB) {
    Math_Vec3f_DistXYZ((u8 *)actorA + 0x24, (u8 *)actorB + 0x24, actorA, actorB);
}
