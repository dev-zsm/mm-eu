// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_warpstone.h"

void ObjWarpstone_Draw(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    ObjWarpstone* this = (ObjWarpstone*)thisx;

    Gfx_DrawDListOpa(play, sOwlStatueDLs[this->modelIndex]);
    if (this->dyna.actor.home.rot.x != 0) {
        OPEN_DISPS(play->state.gfxCtx);

        Gfx_SetupDL25_Xlu(play->state.gfxCtx);
        Matrix_Translate(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y + 34.0f,
                         this->dyna.actor.world.pos.z, MTXMODE_NEW);
        Matrix_Mult(&play->billboardMtxF, MTXMODE_APPLY);
        Matrix_Translate(0.0f, 0.0f, 30.0f, MTXMODE_APPLY);
        Matrix_Scale(this->dyna.actor.velocity.x, this->dyna.actor.velocity.x, this->dyna.actor.velocity.x,
                     MTXMODE_APPLY);
        Matrix_Push();
        gDPPipeSync(POLY_XLU_DISP++);
        gDPSetPrimColor(POLY_XLU_DISP++, 128, 128, 255, 255, 200, this->dyna.actor.home.rot.x);
        gDPSetEnvColor(POLY_XLU_DISP++, 100, 200, 0, 255);
        Matrix_RotateZF(BINANG_TO_RAD_ALT2((play->gameplayFrames * 1500) & 0xFFFF), MTXMODE_APPLY);
        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_XLU_DISP++, gEffFlash1DL);
        Matrix_Pop();
        Matrix_RotateZF(BINANG_TO_RAD_ALT2(~((play->gameplayFrames * 1200) & 0xFFFF)), MTXMODE_APPLY);
        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_XLU_DISP++, gEffFlash1DL);

        CLOSE_DISPS(play->state.gfxCtx);
    }
}
