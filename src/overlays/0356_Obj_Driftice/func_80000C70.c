// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_driftice.h"

void ref_func_80A671E0(ObjDriftice* this, PlayState* play) {
    f32 phi_f0;
    Vec3f sp40;
    f32 sp3C;
    f32 phi_f12;
    Vec3s* points;
    s32 sp30;
    Actor* thisx = &this->dyna.actor;

    Math_Vec3s_ToVec3f(&sp40, &(&this->pathPoints[this->unk_164])[this->unk_168]);
    Math_Vec3f_Diff(&sp40, &this->dyna.actor.world.pos, &thisx->velocity);

    sp3C = Math3D_Vec3fMagnitude(&thisx->velocity);
    if (sp3C < (this->unk_23C * 8.0f)) {
        phi_f0 = this->unk_23C * 0.4f;
        phi_f12 = this->unk_23C * 0.05f;
    } else {
        phi_f0 = this->unk_23C;
        phi_f12 = this->unk_23C * 0.13f;
    }

    Math_StepToF(&this->dyna.actor.speed, phi_f0, phi_f12);

    if ((this->dyna.actor.speed + 0.05f) < sp3C) {
        Math_Vec3f_Scale(&this->dyna.actor.velocity, this->dyna.actor.speed / sp3C);
        this->dyna.actor.world.pos.x += this->dyna.actor.velocity.x;
        this->dyna.actor.world.pos.y += this->dyna.actor.velocity.y;
        this->dyna.actor.world.pos.z += this->dyna.actor.velocity.z;
    } else {
        sp30 = true;
        this->unk_164 += this->unk_168;

        if (1) {}

        this->dyna.actor.speed *= 0.5f;
        if (((this->unk_164 >= this->unk_160) && (this->unk_168 > 0)) ||
            ((this->unk_164 <= 0) && (this->unk_168 < 0))) {
            if (!OBJDRIFTICE_GET_1000(&this->dyna.actor)) {
                this->unk_168 = -this->unk_168;
                ref_func_80A674A8(this);
            } else {
                points = &this->pathPoints[this->unk_160];

                if (this->unk_168 > 0) {
                    this->unk_164 = 0;
                } else {
                    this->unk_164 = this->unk_160;
                }

                if ((this->pathPoints[0].x != points->x) || (this->pathPoints[0].y != points->y) ||
                    (this->pathPoints[0].z != points->z)) {
                    ref_func_80A6743C(this);
                    DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
                    sp30 = false;
                }
            }
        }

        if (sp30) {
            ref_func_80A66570(this, this->unk_164);
        }
    }
}
