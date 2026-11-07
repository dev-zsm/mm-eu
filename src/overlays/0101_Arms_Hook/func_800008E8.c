// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_arms_hook.h"

void ArmsHook_Draw(Actor* thisx, PlayState* play) {
    ArmsHook* this = (ArmsHook*)thisx;
    f32 f0;
    Player* player = GET_PLAYER(play);

    if ((player->actor.draw != NULL) && (player->rightHandType == PLAYER_MODELTYPE_RH_HOOKSHOT)) {
        Vec3f sp68;
        Vec3f sp5C;
        Vec3f sp50;
        f32 sp4C;
        f32 sp48;

        OPEN_DISPS(play->state.gfxCtx);

        if ((ArmsHook_Shoot != this->actionFunc) || (this->timer <= 0)) {
            Matrix_MultVec3f(&ref_D_808C1C10, &this->unk1E0);
            Matrix_MultVec3f(&ref_D_808C1C28, &sp5C);
            Matrix_MultVec3f(&ref_D_808C1C34, &sp50);
            this->weaponInfo.active = false;
        } else {
            Matrix_MultVec3f(&ref_D_808C1C1C, &this->unk1E0);
            Matrix_MultVec3f(&ref_D_808C1C40, &sp5C);
            Matrix_MultVec3f(&ref_D_808C1C4C, &sp50);
        }
        ref_func_80126440(play, &this->collider, &this->weaponInfo, &sp5C, &sp50);
        Gfx_SetupDL25_Opa(play->state.gfxCtx);
        ref_func_80122868(play, player);

        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_OPA_DISP++, object_link_child_DL_01D960);
        Matrix_Translate(this->actor.world.pos.x, this->actor.world.pos.y, this->actor.world.pos.z, MTXMODE_NEW);
        Math_Vec3f_Diff(&player->rightHandWorld.pos, &this->actor.world.pos, &sp68);
        sp48 = SQXZ(sp68);
        sp4C = sqrtf(SQXZ(sp68));
        Matrix_RotateYS(Math_Atan2S(sp68.x, sp68.z), MTXMODE_APPLY);
        Matrix_RotateXS(Math_Atan2S(-sp68.y, sp4C), MTXMODE_APPLY);
        f0 = sqrtf(SQ(sp68.y) + sp48);
        Matrix_Scale(0.015f, 0.015f, f0 * 0.01f, MTXMODE_APPLY);
        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_OPA_DISP++, gHookshotChainDL);
        ref_func_801229A0(play, player);

        CLOSE_DISPS(play->state.gfxCtx);
    }
}
