// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kaleido_scope_NES.h"

s16 func_8000D388(PlayState* play, Vtx* vtx, s16 vtxPage, s16 numQuads) {
    PauseContext* pauseCtx = &play->pauseCtx;
    GameOverContext* gameOverCtx = &play->gameOverCtx;
    s16* quadsX;
    s16* quadsWidth;
    s16* quadsY;
    s16* quadsHeight;
    s16 pageBgQuadX;
    s16 pageBgQuadY;
    s16 i;
    s16 j;
    s16 k;

    

    pageBgQuadX = 0 - (PAGE_BG_COLS * PAGE_BG_QUAD_WIDTH) / 2 - PAGE_BG_QUAD_WIDTH;

    
    for (k = 0, i = 0; i < 3; i++) {
        pageBgQuadX += PAGE_BG_QUAD_WIDTH;

        
        for (pageBgQuadY = (PAGE_BG_ROWS * PAGE_BG_QUAD_HEIGHT) / 2, j = 0; j < 5; j++, k += 4, pageBgQuadY -= 32) {
            vtx[k + 0].v.ob[0] = vtx[k + 2].v.ob[0] = pageBgQuadX;
            vtx[k + 1].v.ob[0] = vtx[k + 3].v.ob[0] = vtx[k + 0].v.ob[0] + PAGE_BG_QUAD_WIDTH;

            vtx[k + 0].v.ob[1] = vtx[k + 1].v.ob[1] = pageBgQuadY + pauseCtx->offsetY;
            vtx[k + 2].v.ob[1] = vtx[k + 3].v.ob[1] = vtx[k + 0].v.ob[1] - PAGE_BG_QUAD_HEIGHT;

            vtx[k + 0].v.ob[2] = vtx[k + 1].v.ob[2] = vtx[k + 2].v.ob[2] = vtx[k + 3].v.ob[2] = 0;

            vtx[k + 0].v.flag = vtx[k + 1].v.flag = vtx[k + 2].v.flag = vtx[k + 3].v.flag = 0;

            vtx[k + 0].v.tc[0] = vtx[k + 0].v.tc[1] = 0;
            vtx[k + 1].v.tc[1] = vtx[k + 2].v.tc[0] = 0;
            vtx[k + 1].v.tc[0] = vtx[k + 3].v.tc[0] = PAGE_BG_QUAD_TEX_WIDTH * (1 << 5);
            vtx[k + 2].v.tc[1] = vtx[k + 3].v.tc[1] = PAGE_BG_QUAD_TEX_HEIGHT * (1 << 5);

            vtx[k + 0].v.cn[0] = vtx[k + 2].v.cn[0] = vtx[k + 0].v.cn[1] = vtx[k + 2].v.cn[1] = vtx[k + 0].v.cn[2] =
                vtx[k + 2].v.cn[2] = 0;

            vtx[k + 1].v.cn[0] = vtx[k + 3].v.cn[0] = vtx[k + 1].v.cn[1] = vtx[k + 3].v.cn[1] = vtx[k + 1].v.cn[2] =
                vtx[k + 3].v.cn[2] = 0;

            vtx[k + 0].v.cn[3] = vtx[k + 2].v.cn[3] = vtx[k + 1].v.cn[3] = vtx[k + 3].v.cn[3] = pauseCtx->alpha;
        }
    }

    if (numQuads != 0) {
        quadsX = sVtxPageQuadsX[vtxPage];
        quadsWidth = sVtxPageQuadsWidth[vtxPage];
        quadsY = sVtxPageQuadsY[vtxPage];
        quadsHeight = sVtxPageQuadsHeight[vtxPage];

        for (i = 0; i < numQuads; i++, k += 4) {
            vtx[k + 2].v.ob[0] = vtx[k + 0].v.ob[0] = quadsX[i];

            vtx[k + 1].v.ob[0] = vtx[k + 3].v.ob[0] = vtx[k + 0].v.ob[0] + quadsWidth[i];

            if (!IS_PAUSE_STATE_GAMEOVER(pauseCtx)) {
                vtx[k + 0].v.ob[1] = vtx[k + 1].v.ob[1] = quadsY[i] + pauseCtx->offsetY;
            } else if (gameOverCtx->state == GAMEOVER_INACTIVE) {
                vtx[k + 0].v.ob[1] = vtx[k + 1].v.ob[1] = quadsY[i] + pauseCtx->offsetY;
            } else {
                vtx[k + 0].v.ob[1] = vtx[k + 1].v.ob[1] = sVtxPageGameOverSaveQuadsY[i] + pauseCtx->offsetY;
            }

            vtx[k + 2].v.ob[1] = vtx[k + 3].v.ob[1] = vtx[k + 0].v.ob[1] - quadsHeight[i];

            vtx[k + 0].v.ob[2] = vtx[k + 1].v.ob[2] = vtx[k + 2].v.ob[2] = vtx[k + 3].v.ob[2] = 0;

            vtx[k + 0].v.flag = vtx[k + 1].v.flag = vtx[k + 2].v.flag = vtx[k + 3].v.flag = 0;

            vtx[k + 0].v.tc[0] = vtx[k + 0].v.tc[1] = vtx[k + 1].v.tc[1] = vtx[k + 2].v.tc[0] = 0;
            vtx[k + 1].v.tc[0] = vtx[k + 3].v.tc[0] = quadsWidth[i] << 5;
            vtx[k + 2].v.tc[1] = vtx[k + 3].v.tc[1] = quadsHeight[i] << 5;

            vtx[k + 0].v.cn[0] = vtx[k + 2].v.cn[0] = vtx[k + 0].v.cn[1] = vtx[k + 2].v.cn[1] = vtx[k + 0].v.cn[2] =
                vtx[k + 2].v.cn[2] = 255;

            vtx[k + 1].v.cn[0] = vtx[k + 3].v.cn[0] = vtx[k + 1].v.cn[1] = vtx[k + 3].v.cn[1] = vtx[k + 1].v.cn[2] =
                vtx[k + 3].v.cn[2] = 255;

            vtx[k + 0].v.cn[3] = vtx[k + 2].v.cn[3] = vtx[k + 1].v.cn[3] = vtx[k + 3].v.cn[3] = pauseCtx->alpha;
        }
    }
    return k;
}
