// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bean.h"

void ref_func_809372D0(ObjBean* this) {
    Actor* actor = &this->dyna.actor;
    Vec3f sp38;
    f32 sp34;
    f32 temp_f2;
    f32 temp_f12;

    Math_Vec3s_ToVec3f(&sp38, &this->pathPoints[this->unk_1DC]);
    Math_Vec3f_Diff(&sp38, &this->unk_1BC, &actor->velocity);

    sp34 = Math3D_Vec3fMagnitude(&actor->velocity);
    temp_f2 = ref_D_80938FF8[this->unk_1DE].x;
    temp_f12 = ref_D_80938FF8[this->unk_1DE].z;
    if (sp34 < (actor->speed * 8.0f)) {
        temp_f2 = ((temp_f2 - 2.0f) * 0.1f) + 2.0f;
        temp_f12 *= 0.4f;
    }

    Math_StepToF(&actor->speed, temp_f2, temp_f12);

    if ((actor->speed + 0.05f) < sp34) {
        Math_Vec3f_Scale(&actor->velocity, actor->speed / sp34);
        this->unk_1BC.x += actor->velocity.x;
        this->unk_1BC.y += actor->velocity.y;
        this->unk_1BC.z += actor->velocity.z;
    } else {
        Math_Vec3f_Copy(&this->unk_1BC, &sp38);
        this->unk_1DA = this->unk_1DC;
        if (this->unk_1DA >= this->unk_1D8) {
            this->unk_1DC = 0;
        } else {
            this->unk_1DC++;
        }
        actor->speed *= 0.5f;
    }
}
