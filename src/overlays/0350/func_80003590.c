// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5E6F0(Actor* thisx, PlayState* play) {
    static Gfx* ref_D_80A5EB68[] = {
        gKakeraLeafTipDL,
        gKakeraLeafMiddleDL,
    };
    EnKusa2* this = (EnKusa2*)thisx;
    s32 i;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);

    for (i = 0; i < ARRAY_COUNT(ref_D_80A5F1C0.unk_0480); i++) {
        EnKusa2UnkBssSubStruct2* s = &ref_D_80A5F1C0.unk_0480[i];

        if (s->unk_2C > 0) {
            Matrix_SetTranslateRotateYXZ(s->unk_04.x, s->unk_04.y, s->unk_04.z, &s->unk_20);
            Matrix_Scale(s->unk_00, s->unk_00, s->unk_00, MTXMODE_APPLY);

            MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
            gSPDisplayList(POLY_OPA_DISP++, ref_D_80A5EB68[i & 1]);
        }
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
