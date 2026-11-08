// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

M2C_UNK Math_Vec3f_Copy(s32, s32);                    /* extern */

s32 Collider_SetLinePoints(struct PlayState *play, struct OcLine *line, struct Vec3f *a, struct Vec3f *b) {
    Math_Vec3f_Copy(line, a);
    Math_Vec3f_Copy((u8 *)line + 0xC, b);
    return 1;
}
