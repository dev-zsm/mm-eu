// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball.h"

void ref_func_80B04D34(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjSnowball* this = (ObjSnowball*)thisx;
    ObjSnowballStruct* ptr;
    s32 i;
    MtxF sp88;
    Vec3s sp80;

    for (i = 0; i < ARRAY_COUNT(this->unk_1A8); i++) {
        ptr = &this->unk_1A8[i];

        if (!(ptr->unk_2D & 1)) {
            sp80.x = ptr->unk_1C.x;
            sp80.y = ptr->unk_1C.y;
            sp80.z = ptr->unk_1C.z;

            Matrix_SetTranslateRotateYXZ(ptr->unk_00.x, ptr->unk_00.y, ptr->unk_00.z, &sp80);
            Matrix_Scale(this->actor.scale.x, this->actor.scale.y, this->actor.scale.z, MTXMODE_APPLY);
            Gfx_DrawDListOpa(play, object_goroiwa_DL_0082D0);

            if ((ptr->unk_28 != NULL) && (ptr->unk_2C > 0)) {
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
