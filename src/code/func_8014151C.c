#include "types.h"

extern void VisFbuf_SetBg(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, f32 a5, f32 a6, f32 a7, f32 a8, s32 a9);

void VisFbuf_SetBgSimple(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    VisFbuf_SetBg(a0, a1, a2, a3, a4, 0.0f, 0.0f, 1.0f, 1.0f, a5);
}
