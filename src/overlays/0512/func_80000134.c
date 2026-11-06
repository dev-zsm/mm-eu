// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_block.h"

s32 ref_func_80B7EB94(BgIkanaBlock* this, PlayState* play) {
    s32 pad;
    Vec3f sp70;
    Vec3f sp64;
    Vec3f sp58;
    CollisionPoly* sp54;
    s32 bgId;
    s32 sp4C = false;
    s16 phi_a0;
    f32 phi_f12;

    if (this->dyna.pushForce > 0.0f) {
        sp4C = true;
    }

    if (sp4C) {
        phi_a0 = this->dyna.yRotation;
    } else {
        phi_a0 = BINANG_ROT180(this->dyna.yRotation);
    }

    sp70.x = this->dyna.actor.world.pos.x;
    sp70.y = this->dyna.actor.world.pos.y + this->unk_170 + 2.0f;
    sp70.z = this->dyna.actor.world.pos.z;

    Matrix_RotateYS(phi_a0, MTXMODE_NEW);

    if (sp4C) {
        phi_f12 = 89.0f;
    } else {
        phi_f12 = 119.0f;
    }

    Matrix_MultVecZ(phi_f12, &sp64);

    sp64.x += this->dyna.actor.world.pos.x;
    sp64.y += this->dyna.actor.world.pos.y + this->unk_170 + 2.0f;
    sp64.z += this->dyna.actor.world.pos.z;

    return !BgCheck_EntityLineTest3(&play->colCtx, &sp70, &sp64, &sp58, &sp54, true, false, false, true, &bgId,
                                    &this->dyna.actor, 0.0f);
}
