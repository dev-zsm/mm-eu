// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_play.h"

void Play_Draw(PlayState* this) {
    GraphicsContext* gfxCtx = this->state.gfxCtx;

    {
        GraphicsContext* gfxCtx2 = this->state.gfxCtx;

        if (sBombersNotebookOpen) {
            if (gSysCfbHiResEnabled != 1) {
                Sched_FlushTaskQueue();
                SysCfb_SetHiResMode();
                gfxCtx2->curFrameBuffer = SysCfb_GetFramebuffer(gfxCtx2->framebufferIndex % 2);
                gfxCtx2->zbuffer = SysCfb_GetZBuffer();
                gfxCtx2->viMode = gActiveViMode;
                gfxCtx2->viConfigFeatures = gViConfigFeatures;
                gfxCtx2->xScale = gViConfigXScale;
                gfxCtx2->yScale = gViConfigYScale;
                gfxCtx2->updateViMode = true;
            }
        } else {
            if (gSysCfbHiResEnabled != 0) {
                Sched_FlushTaskQueue();
                SysCfb_SetLoResMode();
                gfxCtx2->curFrameBuffer = SysCfb_GetFramebuffer(gfxCtx2->framebufferIndex % 2);
                gfxCtx2->zbuffer = SysCfb_GetZBuffer();
                gfxCtx2->viMode = gActiveViMode;
                gfxCtx2->viConfigFeatures = gViConfigFeatures;
                gfxCtx2->xScale = gViConfigXScale;
                gfxCtx2->yScale = gViConfigYScale;
                gfxCtx2->updateViMode = true;
            }
        }
    }

    if (sBombersNotebookOpen && ((SREG(2) != 2) || (gZBufferPtr == NULL))) {
        BombersNotebook_Draw(&sBombersNotebook, gfxCtx);
        Message_Draw(this);
    } else {
        Play_DrawMain(this);
    }
}
