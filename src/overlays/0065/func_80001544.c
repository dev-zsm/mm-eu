// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bom.h"

void EnBom_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    EnBom* this = (EnBom*)thisx;

    OPEN_DISPS(play->state.gfxCtx);

    if (this->actor.params == BOMB_TYPE_BODY) {
        Gfx_SetupDL25_Opa(play->state.gfxCtx);

        Collider_UpdateSpheres(0, &this->collider2);

        if (!this->isPowderKeg) {
            ref_func_800B8050(&this->actor, play, 0);
            Matrix_MultVec3f(&ref_D_80872EE0, &this->actor.home.pos);

            MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
            gSPDisplayList(POLY_OPA_DISP++, gBombCapDL);

            Matrix_ReplaceRotation(&play->billboardMtxF);
            Matrix_RotateXS(0x4000, MTXMODE_APPLY);

            MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
            gDPPipeSync(POLY_OPA_DISP++);
            gDPSetEnvColor(POLY_OPA_DISP++, (s8)this->unk_1F4, 0, 40, 255);
            gDPSetPrimColor(POLY_OPA_DISP++, 0, 0, (s8)this->unk_1F4, 0, 40, 255);
            gSPDisplayList(POLY_OPA_DISP++, gBombBodyDL);
        } else {
            Vec3f sp58;
            Vec3f sp4C;

            if (this->unk_1FA != 0) {
                s16 sp4A = this->actor.world.rot.y - this->actor.shape.rot.y;
                f32 sp44 = (1000.0f / Math_CosS(ABS_ALT((s16)(this->unk_1FA % 10922)) - 0x1555)) + -1000.0f;

                Matrix_RotateYS(sp4A, MTXMODE_APPLY);
                Matrix_Translate(0.0f, sp44, 0.0f, MTXMODE_APPLY);
                Matrix_RotateXS(this->unk_1FA, MTXMODE_APPLY);
                Matrix_RotateYS(-sp4A, MTXMODE_APPLY);
            }

            Matrix_MultVec3f(&ref_D_80872EEC, &this->actor.home.pos);
            Matrix_MultVec3f(&ref_D_80872EF8, &sp58);
            Matrix_MultVec3f(&ref_D_80872F04, &sp4C);

            gDPSetEnvColor(POLY_OPA_DISP++, 255, 255, 255, 255);
            MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
            gSPDisplayList(POLY_OPA_DISP++, gPowderKegBarrelDL);
            gSPDisplayList(POLY_OPA_DISP++, gPowderKegGoronSkullDL);

            ref_func_808726DC(play, &this->actor.home.pos, &sp58, &sp4C, this->timer);
            EnBom_DrawKeg(play, this->timer);
        }
    }

    CLOSE_DISPS(play->state.gfxCtx);
}
