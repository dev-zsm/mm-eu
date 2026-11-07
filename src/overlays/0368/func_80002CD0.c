// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mine.h"

void ObjMine_Path_Draw(Actor* thisx, PlayState* play) {
    s32 pad; 
    ObjMine* this = (ObjMine*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    if (this->actionFunc == ObjMine_Path_Move) {
        Collider_UpdateSpheres(0, &this->collider);
    }

    ref_func_800B8050(&this->actor, play, true);
    Gfx_SetupDL25_Opa(play->state.gfxCtx);

    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gDPSetRenderMode(POLY_OPA_DISP++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);
    gDPSetEnvColor(POLY_OPA_DISP++, 0, 0, 0, 255);
    gSPDisplayList(POLY_OPA_DISP++, object_ny_DL_002068);
    gSPDisplayList(POLY_OPA_DISP++, object_ny_DL_002188);

    CLOSE_DISPS(play->state.gfxCtx);
}
