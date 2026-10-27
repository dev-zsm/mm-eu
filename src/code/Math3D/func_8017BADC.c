// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Math_Vec3f_Diff(s32, s32, M2C_UNK *);         /* extern */
M2C_UNK func_8017BA68(M2C_UNK *, M2C_UNK *, s32);   /* extern */
extern M2C_UNK D_801F34C8;
extern M2C_UNK D_801F34D8;

void func_8017BADC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Math_Vec3f_Diff(arg1, arg0, &D_801F34C8);
    Math_Vec3f_Diff(arg2, arg0, &D_801F34D8);
    func_8017BA68(&D_801F34C8, &D_801F34D8, arg3);
}
