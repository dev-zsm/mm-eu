// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_vspinyroll.h"

void ref_func_80A3C560(ObjVspinyroll* this) {
    f32 magnitude;
    Vec3f* sp20 = &this->unk_39C[this->unk_398 ^ 1];

    Math_Vec3f_Diff(sp20, &this->dyna.actor.world.pos, &this->unk_3B4);
    magnitude = Math3D_Vec3fMagnitude(&this->unk_3B4);
    if (magnitude < 0.01f) {
        Math_Vec3f_Diff(sp20, &this->unk_39C[this->unk_398], &this->unk_3B4);
        magnitude = Math3D_Vec3fMagnitude(&this->unk_3B4);
        if (magnitude < 0.01f) {
            Math_Vec3f_Copy(&this->unk_3B4, &gZeroVec3f);
            return;
        }
    }
    Math_Vec3f_Scale(&this->unk_3B4, 1.0f / magnitude);
}
