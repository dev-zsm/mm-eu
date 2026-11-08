// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

M2C_UNK Math_Vec3f_Copy(s32, M2C_UNK *);              /* extern */
extern M2C_UNK D_801BAE5C;

s32 Collider_InitLine(struct PlayState *play, struct OcLine *line) {
    Math_Vec3f_Copy(line, &D_801BAE5C);
    Math_Vec3f_Copy((u8 *)line + 0xC, &D_801BAE5C);
    return 1;
}
