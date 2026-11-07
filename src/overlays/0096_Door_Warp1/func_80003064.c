// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_warp1.h"

void ref_func_808BB4F4(DoorWarp1* this, PlayState* play2) {
    PlayState* play = play2;
    s32 pad;
    Color_RGB8 sp64[] = {
        { 50, 150, 0 },
        { 100, 150, 200 },
        { 0, 50, 200 },
        { 120, 150, 0 },
    };
    s32 sp60 = 0;

    if (this->unk_1D4 != 0) {
        Matrix_Translate(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y + this->unk_1A4,
                         this->dyna.actor.world.pos.z, MTXMODE_NEW);
        Matrix_Scale(4.0f, this->unk_1AC, 4.0f, MTXMODE_APPLY);
        AnimatedMat_Draw(play, Lib_SegmentedToVirtual(gWarpBossWarpActivationBeamTexAnim));
        Gfx_DrawDListXlu(play, gWarpBossWarpActivationBeamDL);
        return;
    }

    if (play->sceneId != SCENE_MITURIN) {
        if (play->sceneId == SCENE_HAKUGIN) {
            sp60 = 1;
        } else if (play->sceneId == SCENE_SEA) {
            sp60 = 2;
        } else if (play->sceneId == SCENE_INISIE_R) {
            sp60 = 3;
        }
    }

    Matrix_Translate(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y, this->dyna.actor.world.pos.z,
                     MTXMODE_NEW);
    Matrix_RotateYS(this->dyna.actor.world.rot.y, MTXMODE_APPLY);
    Matrix_Scale(1.0f, this->unk_1A8, 1.0f, MTXMODE_APPLY);
    AnimatedMat_Draw(play, Lib_SegmentedToVirtual(gWarpBossWarpLightShaftsTexAnim));

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    gDPSetEnvColor(POLY_XLU_DISP++, sp64[sp60].r, sp64[sp60].g, sp64[sp60].b, 255);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 255, 255, 255, 255);
    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_XLU_DISP++, gWarpBossWarpLightShaftsDL);

    CLOSE_DISPS(play->state.gfxCtx);

    OPEN_DISPS(play->state.gfxCtx);

    AnimatedMat_Draw(play, Lib_SegmentedToVirtual(gWarpBossWarpGlowTexAnim));
    Matrix_Translate(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y, this->dyna.actor.world.pos.z,
                     MTXMODE_NEW);
    Matrix_RotateYS(this->dyna.actor.world.rot.y, MTXMODE_APPLY);
    Matrix_Scale(1.0f, 0.0f, 1.0f, MTXMODE_APPLY);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);

    gDPSetEnvColor(POLY_XLU_DISP++, sp64[sp60].r, sp64[sp60].g, sp64[sp60].b, 255);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x80, 255, 255, 255, this->unk_203);
    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_XLU_DISP++, gWarpBossWarpGlowDL);

    CLOSE_DISPS(play->state.gfxCtx);
}
