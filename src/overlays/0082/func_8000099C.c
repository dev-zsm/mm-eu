// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_boom.h"

void EnBoom_Draw(Actor* thisx, PlayState* play) {
    EnBoom* this = (EnBoom*)thisx;
    EnBoomStruct* sp58 = &ref_D_808A3078[this->actor.params];
    Vec3f sp4C;
    Vec3f sp40;

    OPEN_DISPS(play->state.gfxCtx);

    Matrix_RotateYS(this->actor.world.rot.y, MTXMODE_APPLY);
    Matrix_RotateZS((this->actor.params != ZORA_BOOMERANG_LEFT) ? 0x1F40 : -0x1F40, MTXMODE_APPLY);
    Matrix_RotateXS(this->actor.world.rot.x, MTXMODE_APPLY);
    Matrix_MultVec3f(&sp58->unk_04, &sp4C);
    Matrix_MultVec3f(&sp58->unk_10, &sp40);

    if (ref_func_80126440(play, &this->collider, &this->weaponInfo, &sp4C, &sp40)) {
        EffectBlure_AddVertex(Effect_GetByIndex(this->effectIndex), &sp4C, &sp40);
    }

    Gfx_SetupDL25_Opa(play->state.gfxCtx);
    Matrix_RotateYS(this->unk_1CD * 0x2EE0, MTXMODE_APPLY);

    MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
    gSPDisplayList(POLY_OPA_DISP++, sp58->unk_00);

    CLOSE_DISPS(play->state.gfxCtx);
}
