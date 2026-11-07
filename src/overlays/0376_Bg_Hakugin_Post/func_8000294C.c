// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

void ref_func_80A9D61C(Actor* thisx, PlayState* play) {
    static Gfx* ref_D_80A9D900[] = {
        object_hakugin_obj_DL_00C1A8, object_hakugin_obj_DL_00C568, NULL, NULL,
        object_hakugin_obj_DL_00CA38, object_hakugin_obj_DL_00CEC8, NULL,
    };
    static Gfx* ref_D_80A9D91C[] = {
        object_hakugin_obj_DL_00D098,
        object_hakugin_obj_DL_00D098,
        object_hakugin_obj_DL_00D098,
        object_hakugin_obj_DL_00D098,
    };
    BgHakuginPost* this = (BgHakuginPost*)thisx;
    BgHakuginPostUnkStruct1* unkStruct1;
    BgHakuginPostUnkStruct2* unkStruct2;
    Vec3f sp68;
    s32 i;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    Matrix_SetTranslateRotateYXZ(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                                 this->dyna.actor.world.pos.z, &this->dyna.actor.shape.rot);
    Matrix_Scale(0.1f, 0.1f, 0.1f, MTXMODE_APPLY);

    for (i = 0; i < ref_D_80A9E028.count; i++) {
        unkStruct1 = &ref_D_80A9E028.unk_0000[i];
        if ((unkStruct1->unk_34 != 5) && (unkStruct1->unk_34 != 4)) {
            sp68.x = unkStruct1->unk_14.x + this->dyna.actor.home.pos.x;
            sp68.y = unkStruct1->unk_14.y + this->unk_16C;
            sp68.z = unkStruct1->unk_14.z + this->dyna.actor.home.pos.z;
            ref_func_80A9B384(&sp68);

            MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
            gSPDisplayList(POLY_OPA_DISP++, ref_D_80A9D900[unkStruct1->unk_00]);
        }
    }

    if (ref_D_80A9E028.unk_1924) {
        for (i = 0; i < ARRAY_COUNT(ref_D_80A9E028.unk_02A4); i++) {
            unkStruct2 = &ref_D_80A9E028.unk_02A4[i];
            if (unkStruct2->unk_2C > 0) {
                Matrix_SetTranslateRotateYXZ(unkStruct2->unk_04.x, unkStruct2->unk_04.y, unkStruct2->unk_04.z,
                                             &unkStruct2->unk_20);
                Matrix_Scale(unkStruct2->unk_00, unkStruct2->unk_00, unkStruct2->unk_00, MTXMODE_APPLY);

                MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
                gSPDisplayList(POLY_OPA_DISP++, ref_D_80A9D91C[unkStruct2->unk_2D]);
            }
        }
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
