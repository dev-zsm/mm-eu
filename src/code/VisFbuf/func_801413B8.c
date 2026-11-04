// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_visfbuf.h"

void VisFbuf_SetBg(Gfx** gfxP, void* source, void* img, s32 width, s32 height, f32 x, f32 y, f32 scaleX, f32 scaleY,
                   VisFbufBgMode cycleMode) {
    Gfx* gfx = *gfxP;
    Gfx* gfxTemp;
    uObjBg* bg;

    
    gfxTemp = gfx;
    bg = Gfx_Alloc(&gfxTemp, sizeof(uObjBg));
    gfx = gfxTemp;

    
    bg->b.imageX = 0;
    bg->b.imageW = width << 2;
    bg->b.frameX = x * 4;
    bg->b.frameW = width << 2;
    bg->b.imageY = 0;
    bg->b.imageH = height << 2;
    bg->b.frameY = y * 4;
    bg->b.frameH = height << 2;
    bg->b.imageLoad = G_BGLT_LOADTILE;
    bg->b.imageFmt = G_IM_FMT_RGBA;
    bg->b.imageSiz = G_IM_SIZ_16b;
    bg->b.imagePal = 0;
    bg->b.imageFlip = 0;
    bg->b.imagePtr = source;

    if (!!(cycleMode & VIS_FBUF_BG_CYC_COPY) != 0) { 
        guS2DInitBg(bg);
    } else {
        bg->s.scaleW = (s32)((1 << 10) / scaleX);
        bg->s.scaleH = (s32)((1 << 10) / scaleY);
        bg->s.imageYorig = bg->b.imageY;
    }

    
    VisFbuf_DrawBgToColorImage(&gfx, bg, img, width, height, cycleMode);

    *gfxP = gfx;
}
