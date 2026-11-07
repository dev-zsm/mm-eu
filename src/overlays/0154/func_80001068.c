// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bombiwa.h"

void ref_func_8093A418(Actor* thisx, PlayState* play) {
    ObjBombiwa* this = (ObjBombiwa*)thisx;
    f32 sp28;

    if ((this->actor.projectedPos.z <= 2200.0f) || ((this->unk_203 & 1) && (this->actor.projectedPos.z < 2300.0f))) {
        this->actor.shape.shadowAlpha = 160;
        Gfx_DrawDListOpa(play, object_bombiwa_DL_0009E0);
        return;
    }

    if (this->actor.projectedPos.z < 2300.0f) {
        OPEN_DISPS(play->state.gfxCtx);

        sp28 = (2300.0f - this->actor.projectedPos.z) * 2.55f;

        this->actor.shape.shadowAlpha = sp28 * (160.0f / 255.0f);
        Gfx_SetupDL25_Xlu(play->state.gfxCtx);

        MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 255, 255, 255, (s32)sp28);
        gSPDisplayList(POLY_XLU_DISP++, object_bombiwa_DL_000AF0);

        CLOSE_DISPS(play->state.gfxCtx);
    } else {
        this->actor.shape.shadowAlpha = 0;
    }
}
