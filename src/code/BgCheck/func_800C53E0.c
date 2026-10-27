// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK BgCheck_CheckLineImpl(s32, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, s32, f32, s32); /* extern */
s32 BgCheck_GetBccFlags(s32, s32, s32, s32, s32);         /* extern */

void BgCheck_EntityLineTest2(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10) {
    BgCheck_CheckLineImpl(arg0, 2, 0, arg1, arg2, arg3, arg4, arg9, arg10, 1.0f, BgCheck_GetBccFlags(arg5, arg6, arg7, arg8, 1));
}
