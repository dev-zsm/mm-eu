// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_kendo_kanban.h"

void ObjKendoKanban_Draw(Actor* thisx, PlayState* play) {
    ObjKendoKanban* this = (ObjKendoKanban*)thisx;
    s32 i;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);

    if (this->boardFragments == OBJKENDOKANBAN_PART_FULL) {
        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_OPA_DISP++, gKendoKanbanDL);
    } else {
        Matrix_RotateAxisS(this->rotAngle, &this->rotAxis, MTXMODE_APPLY);
        Matrix_Translate(-this->rootCornerPos.x, -this->rootCornerPos.y, -this->rootCornerPos.z, MTXMODE_APPLY);
        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);

        
        for (i = 0; i < ARRAY_COUNT(sDisplayLists); i++) {
            if ((1 << i) & this->boardFragments) {
                gSPDisplayList(POLY_OPA_DISP++, sDisplayLists[i]);
            }
        }
    }

    CLOSE_DISPS(play->state.gfxCtx);

    
    for (i = 0; i < ARRAY_COUNT(this->cornerPos); i++) {
        Matrix_MultVec3f(&this->cornerPoints[i], &this->cornerPos[i]);
    }
    Matrix_MultVec3f(&this->centerPoint, &this->centerPos);
}
