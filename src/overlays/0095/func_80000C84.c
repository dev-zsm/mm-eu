// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_breakwall.h"

void BgBreakwall_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    BgBreakwall* this = (BgBreakwall*)thisx;
    BgBreakwallStruct* temp_s2 = &ref_D_808B8140[BGBREAKWALL_GET_F(&this->dyna.actor)];

    OPEN_DISPS(play->state.gfxCtx);

    if (temp_s2->unk_0C != NULL) {
        AnimatedMat_Draw(play, temp_s2->unk_0C);
    }

    if (temp_s2->unk_1C != NULL) {
        temp_s2->unk_1C(&this->dyna.actor, play);
    }

    if (temp_s2->unk_04 != NULL) {
        Gfx_SetupDL25_Opa(play->state.gfxCtx);

        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_OPA_DISP++, temp_s2->unk_04);
    }

    if (temp_s2->unk_08 != NULL) {
        Gfx_SetupDL25_Xlu(play->state.gfxCtx);

        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_XLU_DISP++, temp_s2->unk_08);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
