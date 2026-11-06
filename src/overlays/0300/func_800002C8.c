// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_spinyroll.h"

void ref_func_80A1DD18(ObjSpinyroll* this) {
    f32 temp_f0;
    Vec3f* sp20 = &this->unk_4AC[this->unk_4A8 ^ 1];

    Math_Vec3f_Diff(sp20, &this->dyna.actor.world.pos, &this->unk_4C4);

    temp_f0 = Math3D_Vec3fMagnitude(&this->unk_4C4);
    if (temp_f0 < 0.01f) {
        Math_Vec3f_Diff(sp20, &this->unk_4AC[this->unk_4A8], &this->unk_4C4);

        temp_f0 = Math3D_Vec3fMagnitude(&this->unk_4C4);
        if (temp_f0 < 0.01f) {
            Math_Vec3f_Copy(&this->unk_4C4, &gZeroVec3f);
            return;
        }
    }
    Math_Vec3f_Scale(&this->unk_4C4, 1.0f / temp_f0);
}
