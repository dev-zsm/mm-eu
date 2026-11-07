// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hgdoor.h"

void ObjHgdoor_Draw(Actor* thisx, PlayState* play) {
    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);

    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    if (OBJHGDOOR_IS_RIGHT_DOOR(thisx)) {
        gSPDisplayList(POLY_OPA_DISP++, object_hgdoor_DL_001AB0);
        gSPDisplayList(POLY_OPA_DISP++, object_hgdoor_DL_001BA8);
    } else {
        gSPDisplayList(POLY_OPA_DISP++, object_hgdoor_DL_001670);
        gSPDisplayList(POLY_OPA_DISP++, object_hgdoor_DL_001768);
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
