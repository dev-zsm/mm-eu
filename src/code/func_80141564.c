// FLAGS: -O2 -g3 -mips2
#include "types.h"

void VisFbuf_SetBg(s32, s32, s32, s32, s32, f32, f32, f32, f32, s32);

void VisFbuf_SetBgGeneral(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, s32 arg9) {
    VisFbuf_SetBg(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
}
