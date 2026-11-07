// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_balance.h"

void BgDblueBalance_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    BgDblueBalance* this = (BgDblueBalance*)thisx;
    BgDblueBalanceTypeInfo* ptr2 = &sTypeInfo[BGDBLUEBALANCE_GET_300(&this->dyna.actor)];
    BgDblueBalance* sp38;
    Gfx* gfx;

    Gfx_DrawDListOpa(play, ptr2->opaDList);

    if (!(BGDBLUEBALANCE_GET_300(&this->dyna.actor)) && (this->unk_160 != NULL)) {
        AnimatedMat_Draw(play, ref_D_80B83C74);
        sp38 = this->unk_160;
        Matrix_SetTranslateRotateYXZ(sp38->dyna.actor.world.pos.x, sp38->dyna.actor.world.pos.y,
                                     sp38->dyna.actor.world.pos.z, &sp38->dyna.actor.shape.rot);
        Matrix_Translate(30.0f, 15.0f, 0.0f, MTXMODE_APPLY);
        Matrix_Scale(sp38->dyna.actor.scale.x, sp38->dyna.actor.scale.y, sp38->dyna.actor.scale.z, MTXMODE_APPLY);

        OPEN_DISPS(play->state.gfxCtx);

        gfx = POLY_XLU_DISP;

        gSPDisplayList(gfx++, gSetupDLs[SETUPDL_25]);
        MATRIX_FINALIZE_AND_LOAD(gfx++, play->state.gfxCtx);
        gDPSetEnvColor(gfx++, 0, 0, 0, this->unk_183);
        gSPDisplayList(gfx++, gGreatBayTempleObjectSeesawSplashDL);

        POLY_XLU_DISP = gfx;

        CLOSE_DISPS(play->state.gfxCtx);
    }
}
