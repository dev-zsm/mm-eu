// FLAGS: -O2 -g3 -mips2
#include "types.h"

void VisFbuf_SetBg(s32, s32, s32, s32, s32, f32, f32, f32, f32, s32);

void VisFbuf_SetBgGeneral(union Gfx **gfxP, void *source, void *img, s32 width, s32 height, f32 x, f32 y, f32 scaleX, f32 scaleY, s32 cycleMode) {
    VisFbuf_SetBg(gfxP, source, img, width, height, x, y, scaleX, scaleY, cycleMode);
}
