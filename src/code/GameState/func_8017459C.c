// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/game.h"

void GameState_SetFBFilter(Gfx** gfxP, void* zbuffer) {
    Gfx* gfx = *gfxP;

    if ((R_FB_FILTER_TYPE >= FB_FILTER_CVG_RGB) && (R_FB_FILTER_TYPE <= FB_FILTER_CVG_RGB_FOG)) {
        
        sGameVisCvg.vis.type = FB_FILTER_TO_CVG_TYPE(R_FB_FILTER_TYPE);
        sGameVisCvg.vis.primColor.r = R_FB_FILTER_PRIM_COLOR(0);
        sGameVisCvg.vis.primColor.g = R_FB_FILTER_PRIM_COLOR(1);
        sGameVisCvg.vis.primColor.b = R_FB_FILTER_PRIM_COLOR(2);
        sGameVisCvg.vis.primColor.a = R_FB_FILTER_A;
        VisCvg_Draw(&sGameVisCvg, &gfx);
    } else if ((R_FB_FILTER_TYPE == FB_FILTER_ZBUF_IA) || (R_FB_FILTER_TYPE == FB_FILTER_ZBUF_RGBA)) {
        
        sGameVisZBuf.vis.type = (R_FB_FILTER_TYPE == FB_FILTER_ZBUF_RGBA);
        sGameVisZBuf.vis.primColor.r = R_FB_FILTER_PRIM_COLOR(0);
        sGameVisZBuf.vis.primColor.g = R_FB_FILTER_PRIM_COLOR(1);
        sGameVisZBuf.vis.primColor.b = R_FB_FILTER_PRIM_COLOR(2);
        sGameVisZBuf.vis.primColor.a = R_FB_FILTER_A;
        sGameVisZBuf.vis.envColor.r = R_FB_FILTER_ENV_COLOR(0);
        sGameVisZBuf.vis.envColor.g = R_FB_FILTER_ENV_COLOR(1);
        sGameVisZBuf.vis.envColor.b = R_FB_FILTER_ENV_COLOR(2);
        sGameVisZBuf.vis.envColor.a = R_FB_FILTER_A;
        VisZBuf_Draw(&sGameVisZBuf, &gfx, zbuffer);
    } else if (R_FB_FILTER_TYPE == FB_FILTER_MONO) {
        
        sGameVisMono.vis.type = 0;
        sGameVisMono.vis.primColor.r = R_FB_FILTER_PRIM_COLOR(0);
        sGameVisMono.vis.primColor.g = R_FB_FILTER_PRIM_COLOR(1);
        sGameVisMono.vis.primColor.b = R_FB_FILTER_PRIM_COLOR(2);
        sGameVisMono.vis.primColor.a = R_FB_FILTER_A;
        sGameVisMono.vis.envColor.r = R_FB_FILTER_ENV_COLOR(0);
        sGameVisMono.vis.envColor.g = R_FB_FILTER_ENV_COLOR(1);
        sGameVisMono.vis.envColor.b = R_FB_FILTER_ENV_COLOR(2);
        sGameVisMono.vis.envColor.a = R_FB_FILTER_A;
        VisMono_Draw(&sGameVisMono, &gfx);
    }

    *gfxP = gfx;
}
