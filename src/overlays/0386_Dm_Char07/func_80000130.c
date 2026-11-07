// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char07.h"

void DmChar07_Draw(Actor* thisx, PlayState* play) {
    DmChar07* this = (DmChar07*)thisx;
    s32 pad;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    switch (this->dyna.actor.params) {
        case DMCHAR07_STAGE:
            gSPDisplayList(POLY_OPA_DISP++, object_milkbar_DL_002CD0);
            break;

        case DMCHAR07_CREDITS_STAGE:
            AnimatedMat_Draw(play, Lib_SegmentedToVirtual(object_milkbar_Matanimheader_0105F8));
            gSPDisplayList(POLY_OPA_DISP++, object_milkbar_DL_007918);
            gSPDisplayList(POLY_OPA_DISP++, object_milkbar_DL_000240);
            gSPDisplayList(POLY_OPA_DISP++, object_milkbar_DL_000790);
            gSPDisplayList(POLY_OPA_DISP++, object_milkbar_DL_000CC0);
            gSPDisplayList(POLY_OPA_DISP++, object_milkbar_DL_001210);
            gSPDisplayList(POLY_OPA_DISP++, object_milkbar_DL_0016B8);
            break;

        case DMCHAR07_SPOTLIGHTS:
            if (this->spotlightFlags & DMCHAR07_STAGE_RIGHT_SPOTLIGHT) {
                gSPDisplayList(POLY_OPA_DISP++, object_milkbar_DL_000240);
            }
            if (this->spotlightFlags & DMCHAR07_UPSTAGE_RIGHT_SPOTLIGHT) {
                gSPDisplayList(POLY_OPA_DISP++, object_milkbar_DL_000790);
            }
            if (this->spotlightFlags & DMCHAR07_STAGE_CENTER_SPOTLIGHT) {
                gSPDisplayList(POLY_OPA_DISP++, object_milkbar_DL_000CC0);
            }
            if (this->spotlightFlags & DMCHAR07_UPSTAGE_LEFT_SPOTLIGHT) {
                gSPDisplayList(POLY_OPA_DISP++, object_milkbar_DL_001210);
            }
            if (this->spotlightFlags & DMCHAR07_DOWNSTAGE_CENTER_SPOTLIGHT) {
                gSPDisplayList(POLY_OPA_DISP++, object_milkbar_DL_0016B8);
            }
            break;

        case DMCHAR07_DISHES:
            gSPDisplayList(POLY_OPA_DISP++, object_milkbar_DL_010D68);
            break;

        default:
            break;
    }

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);
    MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);

    switch (this->dyna.actor.params) {
        case DMCHAR07_STAGE:
            gSPDisplayList(POLY_XLU_DISP++, object_milkbar_DL_002BA0);
            break;

        case DMCHAR07_CREDITS_STAGE:
            gSPDisplayList(POLY_XLU_DISP++, object_milkbar_DL_0076A0);
            gSPDisplayList(POLY_XLU_DISP++, object_milkbar_DL_000100);
            gSPDisplayList(POLY_XLU_DISP++, object_milkbar_DL_000650);
            gSPDisplayList(POLY_XLU_DISP++, object_milkbar_DL_000B80);
            gSPDisplayList(POLY_XLU_DISP++, object_milkbar_DL_0010D0);
            gSPDisplayList(POLY_XLU_DISP++, object_milkbar_DL_0015E0);
            break;

        case DMCHAR07_SPOTLIGHTS:
            if (this->spotlightFlags & DMCHAR07_STAGE_RIGHT_SPOTLIGHT) {
                gSPDisplayList(POLY_OPA_DISP++, object_milkbar_DL_000100);
            }
            if (this->spotlightFlags & DMCHAR07_UPSTAGE_RIGHT_SPOTLIGHT) {
                gSPDisplayList(POLY_OPA_DISP++, object_milkbar_DL_000650);
            }
            if (this->spotlightFlags & DMCHAR07_STAGE_CENTER_SPOTLIGHT) {
                gSPDisplayList(POLY_OPA_DISP++, object_milkbar_DL_000B80);
            }
            if (this->spotlightFlags & DMCHAR07_UPSTAGE_LEFT_SPOTLIGHT) {
                gSPDisplayList(POLY_OPA_DISP++, object_milkbar_DL_0010D0);
            }
            if (this->spotlightFlags & DMCHAR07_DOWNSTAGE_CENTER_SPOTLIGHT) {
                gSPDisplayList(POLY_OPA_DISP++, object_milkbar_DL_0015E0);
            }
            break;

        case DMCHAR07_DISHES:
            break;

        default:
            break;
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
