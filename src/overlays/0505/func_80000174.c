// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_kin2_shelf.h"

s32 ref_func_80B6FCA4(BgKin2Shelf* this, PlayState* play) {
    s32 pad;
    f32 spA0;
    s16 sp9E;
    Vec3f sp90;
    Vec3f sp84;
    Vec3f sp78;
    Vec3f sp6C;
    Vec3f sp60;
    Vec3f sp54;
    CollisionPoly* sp50;
    s32 bgId;

    if (this->unk_164 & 1) {
        sp9E = 0;
    } else {
        sp9E = -0x8000;
    }

    spA0 = ref_D_80B70758[0] + ((this->dyna.pushForce < 0.0f) ? 28.0f : -2.0f) + ref_D_80B70770[0];

    Matrix_Translate(0.0f, 10.0f, *ref_D_80B70760, MTXMODE_NEW);
    Matrix_RotateYS(sp9E, MTXMODE_APPLY);

    sp54.x = 0.0f;
    sp54.y = 0.0f;
    sp54.z = 0.0f;

    Matrix_MultVec3f(&sp54, &sp90);

    sp54.z = spA0;

    Matrix_MultVec3f(&sp54, &sp84);
    Matrix_SetTranslateRotateYXZ(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                                 this->dyna.actor.world.pos.z, &this->dyna.actor.shape.rot);
    Matrix_MultVec3f(&sp90, &sp78);
    Matrix_MultVec3f(&sp84, &sp6C);

    return BgCheck_EntityLineTest3(&play->colCtx, &sp78, &sp6C, &sp60, &sp50, true, false, false, true, &bgId,
                                   &this->dyna.actor, 0.0f);
}
