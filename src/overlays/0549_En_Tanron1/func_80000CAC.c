// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_tanron1.h"

void ref_func_80BB5AAC(EnTanron1* this, PlayState* play) {
    EnTanron1Struct* ptrBase = &this->unk_160[0];
    s16 i;
    u8 flag = 0;
    EnTanron1Struct* ptr = ptrBase;

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL25_Opa(play->state.gfxCtx);

    for (i = 0; i < this->actor.params; i++, ptr++) {
        if (ptr->unk_24 == 1) {
            if (!flag) {
                gSPDisplayList(POLY_OPA_DISP++, ovl_En_Tanron1_DL_001888);
                flag++;
            }
            Matrix_Translate(ptr->unk_00.x, ptr->unk_00.y, ptr->unk_00.z, MTXMODE_NEW);
            Matrix_RotateYS(ptr->unk_1A, MTXMODE_APPLY);
            Matrix_RotateXS(ptr->unk_18 * -1, MTXMODE_APPLY);
            Matrix_Scale(1.2f, ptr->unk_2C, 1.2f, MTXMODE_APPLY);

            MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
            gSPDisplayList(POLY_OPA_DISP++, ovl_En_Tanron1_DL_001900);
        }
    }

    flag = 0;
    ptr = ptrBase;
    for (i = 0; i < this->actor.params; i++, ptr++) {
        if (ptr->unk_24 == 2) {
            if (!flag) {
                gSPDisplayList(POLY_OPA_DISP++, ovl_En_Tanron1_DL_001888);
                gDPLoadTextureBlock(POLY_OPA_DISP++, ovl_En_Tanron1_DL_001428, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 32, 0,
                                    G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 4, 5, G_TX_NOLOD,
                                    G_TX_NOLOD);
                flag++;
            }

            Matrix_Translate(ptr->unk_00.x, ptr->unk_00.y, ptr->unk_00.z, MTXMODE_NEW);
            Matrix_RotateYS(ptr->unk_1A, MTXMODE_APPLY);
            Matrix_RotateXS(ptr->unk_18 * -1, MTXMODE_APPLY);
            Matrix_Scale(1.0f, ptr->unk_2C, 1.0f, MTXMODE_APPLY);

            MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
            gSPDisplayList(POLY_OPA_DISP++, ovl_En_Tanron1_DL_001900);
        }
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
