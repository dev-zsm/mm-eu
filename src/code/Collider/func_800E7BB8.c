// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void Collider_UpdateCylinder(struct Actor *actor, struct ColliderCylinder *cyl) {
    M2C_FIELD(cyl, s16 *, 0x46) = (s16) (s32) M2C_FIELD(actor, f32 *, 0x24);
    M2C_FIELD(cyl, s16 *, 0x48) = (s16) (s32) M2C_FIELD(actor, f32 *, 0x28);
    M2C_FIELD(cyl, s16 *, 0x4A) = (s16) (s32) M2C_FIELD(actor, f32 *, 0x2C);
}
