// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

void ref_func_80942B1C(EnGoroiwa* this, PlayState* play) {
    s32 pad;
    s32 pad2;
    s32 i;
    EnGoroiwaStruct* ptr;
    s32 params = ENGOROIWA_GET_C000(&this->actor);
    Gfx* phi_fp;
    MtxF sp88;
    Vec3s sp80;

    if (params == ENGOROIWA_C000_1) {
        phi_fp = object_goroiwa_DL_0032E0;
    } else {
        phi_fp = object_goroiwa_DL_0082D0;
    }

    for (i = 0; i < ARRAY_COUNT(this->unk_1E8); i++) {
        ptr = &this->unk_1E8[i];

        if (!(ptr->unk_2D & 1)) {
            sp80.x = ptr->unk_1C;
            sp80.y = ptr->unk_1E;
            sp80.z = ptr->unk_20;

            Matrix_SetTranslateRotateYXZ(ptr->unk_00.x, ptr->unk_00.y, ptr->unk_00.z, &sp80);
            Matrix_Scale(this->actor.scale.x, this->actor.scale.y, this->actor.scale.z, MTXMODE_APPLY);
            Gfx_DrawDListOpa(play, phi_fp);

            if ((ptr->unk_28 != 0) && (ptr->unk_2C > 0)) {
                OPEN_DISPS(play->state.gfxCtx);

                Gfx_SetupDL44_Xlu(play->state.gfxCtx);

                gDPSetCombineLERP(POLY_XLU_DISP++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0,
                                  0, COMBINED);
                gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 0, 0, 0, ptr->unk_2C);

                ref_func_800C0094(ptr->unk_28, ptr->unk_00.x, ptr->unk_18, ptr->unk_00.z, &sp88);
                Matrix_Put(&sp88);
                Matrix_Scale(this->actor.scale.x * 7.5f, 1.0f, this->actor.scale.z * 7.5f, MTXMODE_APPLY);

                MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
                gSPDisplayList(POLY_XLU_DISP++, gCircleShadowDL);

                CLOSE_DISPS(play->state.gfxCtx);
            }
        }
    }
}
