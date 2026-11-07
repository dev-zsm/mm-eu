// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_hina.h"

void ref_func_80A1F9AC(DmHina* this, PlayState* play) {
    GraphicsContext* gfxCtx = play->state.gfxCtx;

    if (this->unk17E != 0) {
        OPEN_DISPS(gfxCtx);

        Gfx_SetupDL25_Xlu(play->state.gfxCtx);

        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, (u8)(this->unk14C * 100.0f) + 155, this->unk17F);
        gDPSetEnvColor(POLY_XLU_DISP++, 255, 255, (u8)(this->unk150 * 100.0f) + 50, 0);
        gSPDisplayList(POLY_XLU_DISP++, gLightOrbMaterial1DL);

        Matrix_Translate(this->actor.world.pos.x,
                         this->actor.world.pos.y + (this->unk154 * this->unk15C) + (40.0f * this->unk15C),
                         this->actor.world.pos.z, MTXMODE_NEW);
        Matrix_ReplaceRotation(&play->billboardMtxF);
        Matrix_Scale(this->unk14C * 20.0f, this->unk14C * 20.0f, this->unk14C * 20.0f, MTXMODE_APPLY);
        Matrix_RotateZF(Rand_ZeroFloat(2 * M_PIf), MTXMODE_APPLY);

        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, gfxCtx);
        gSPDisplayList(POLY_XLU_DISP++, gLightOrbModelDL);

        CLOSE_DISPS(gfxCtx);
    }
}
