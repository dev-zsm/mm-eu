// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

M2C_UNK Math_SmoothStepToS(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */

s32 Actor_TrackNone(struct Vec3s *headRot, struct Vec3s *torsoRot) {
    Math_SmoothStepToS((u8 *)headRot + 2, 0, 6, 0x1838, 0x64);
    Math_SmoothStepToS(headRot, 0, 6, 0x1838, 0x64);
    Math_SmoothStepToS((u8 *)torsoRot + 2, 0, 6, 0x1838, 0x64);
    Math_SmoothStepToS(torsoRot, 0, 6, 0x1838, 0x64);
    return 1;
}
