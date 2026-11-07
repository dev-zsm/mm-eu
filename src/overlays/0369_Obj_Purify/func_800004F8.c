// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_purify.h"

void ref_func_80A851C8(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjPurify* this = (ObjPurify*)thisx;
    ObjPurifyInfo* info = &sObjPurifyInfo[OBJPURIFY_GET_INFO_INDEX(&this->dyna.actor)];
    Gfx* opaDList = info->opaDLists[this->gfxIndex];
    Gfx* xluDList = info->xluDLists[this->gfxIndex];
    AnimatedMaterial* animMat = info->animMat[this->gfxIndex];

    OPEN_DISPS(play->state.gfxCtx);

    if (animMat != NULL) {
        AnimatedMat_Draw(play, Lib_SegmentedToVirtual(animMat));
    }
    if (opaDList != NULL) {
        Gfx_SetupDL25_Opa(play->state.gfxCtx);
        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_OPA_DISP++, opaDList);
    }
    if (xluDList != NULL) {
        Gfx_SetupDL25_Xlu(play->state.gfxCtx);
        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_XLU_DISP++, xluDList);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
