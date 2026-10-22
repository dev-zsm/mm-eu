// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK BgCheck_Vec3sToVec3f(s32, s32);                    /* extern */

void CollisionPoly_GetVertices(void *arg0, s32 arg1, s32 arg2) {
    BgCheck_Vec3sToVec3f(((M2C_FIELD(arg0, u16 *, 2) & 0x1FFF) * 6) + arg1, arg2);
    BgCheck_Vec3sToVec3f(((M2C_FIELD(arg0, u16 *, 4) & 0x1FFF) * 6) + arg1, arg2 + 0xC);
    BgCheck_Vec3sToVec3f((M2C_FIELD(arg0, u16 *, 6) * 6) + arg1, arg2 + 0x18);
}
