// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_purify.h"

void ref_func_80A85304(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjPurify* this = (ObjPurify*)thisx;
    ObjPurifyInfo* info = &sObjPurifyInfo[OBJPURIFY_GET_INFO_INDEX(&this->dyna.actor)];
    s32 sp6C[2];
    s32 i;
    s32 index;

    if (this->unk168[1] < this->unk168[0]) {
        sp6C[0] = 1;
        sp6C[1] = 0;
    } else {
        sp6C[0] = 0;
        sp6C[1] = 1;
    }

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Xlu(play->state.gfxCtx);
    for (i = 0; i < ARRAY_COUNT(sp6C); i++) {
        index = sp6C[i];
        AnimatedMat_Draw(play, Lib_SegmentedToVirtual(info->animMat[index]));
        ObjPurify_SetSysMatrix(this->unk168[index]);
        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_XLU_DISP++, info->xluDLists[index]);
    };

    CLOSE_DISPS(play->state.gfxCtx);
}
