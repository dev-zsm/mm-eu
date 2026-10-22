// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Math_Vec3f_Copy(s32, M2C_UNK *);              /* extern */
extern M2C_UNK D_801BAE5C;

s32 Collider_InitLine(s32 arg0, s32 arg1) {
    Math_Vec3f_Copy(arg1, &D_801BAE5C);
    Math_Vec3f_Copy(arg1 + 0xC, &D_801BAE5C);
    return 1;
}
