// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern void guLookAtHiliteF(f32 *mf, u8 *arg1, s32 *arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, f32 arg11, f32 arg12, f32 arg13, f32 arg14, f32 arg15, f32 arg16, f32 arg17, s32 arg18, s32 arg19);
extern void guMtxF2L(f32 *mf, s32 arg1);

void guLookAtHilite(s32 arg0, u8 *arg1, s32 *arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, f32 arg11, f32 arg12, f32 arg13, f32 arg14, f32 arg15, f32 arg16, f32 arg17, s32 arg18, s32 arg19) {
    f32 mf[4][4];

    guLookAtHiliteF(&mf[0][0], arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17, arg18, arg19);
    guMtxF2L(&mf[0][0], arg0);
}
