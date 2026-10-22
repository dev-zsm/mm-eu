// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80124AC8(s32, s32, u8 *);            /* extern */
M2C_UNK func_801257C8(s32, s32);                    /* extern */
M2C_UNK Matrix_Scale(f32, f32, s32, M2C_UNK);      /* extern */
M2C_UNK Matrix_TranslateRotateZYX(s32, s32);                    /* extern */

void func_80126190(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Matrix_TranslateRotateZYX(arg2, arg3);
    func_801257C8(arg2, arg3);
    func_80124AC8(arg1, M2C_FIELD(arg0, s32 *, 0x258), arg0 + 0xAF0);
    Matrix_Scale(M2C_FIELD(arg0, f32 *, 0xAF0), M2C_FIELD(arg0, f32 *, 0xAF4), M2C_FIELD(arg0, s32 *, 0xAF8), 1);
}
