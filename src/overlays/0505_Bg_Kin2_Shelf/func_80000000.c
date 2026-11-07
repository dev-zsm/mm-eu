// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_kin2_shelf.h"

s32 ref_func_80B6FB30(BgKin2Shelf* this, PlayState* play) {
    s32 temp_v1 = BGKIN2SHELF_GET_1(&this->dyna.actor);
    f32 phi_f0;
    f32 spA4;
    s16 spA2;
    Vec3f sp94;
    Vec3f sp88;
    Vec3f sp7C;
    Vec3f sp70;
    Vec3f sp64;
    Vec3f sp58;
    CollisionPoly* sp54;
    s32 bgId;

    if (this->unk_164 & 2) {
        spA2 = 0x4000;
    } else {
        spA2 = -0x4000;
    }

    spA4 = ref_D_80B70750[temp_v1] + ((this->dyna.pushForce < 0.0f) ? 28.0f : -2.0f) + ref_D_80B70768[temp_v1];

    Matrix_Translate(0.0f, 10.0f, ref_D_80B70760[temp_v1], MTXMODE_NEW);
    Matrix_RotateYS(spA2, MTXMODE_APPLY);

    sp58.x = 0.0f;
    sp58.y = 0.0f;
    sp58.z = 0.0f;

    Matrix_MultVec3f(&sp58, &sp94);

    sp58.z = spA4;

    Matrix_MultVec3f(&sp58, &sp88);
    Matrix_SetTranslateRotateYXZ(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                                 this->dyna.actor.world.pos.z, &this->dyna.actor.shape.rot);
    Matrix_MultVec3f(&sp94, &sp7C);
    Matrix_MultVec3f(&sp88, &sp70);

    return BgCheck_EntityLineTest3(&play->colCtx, &sp7C, &sp70, &sp64, &sp54, true, false, false, true, &bgId,
                                   &this->dyna.actor, 0.0f);
}
