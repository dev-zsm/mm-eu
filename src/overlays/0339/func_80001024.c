// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_mkk.h"

void ref_func_80A4EEF4(EnMkk* this) {
    Math_Vec3f_Copy(&this->unk_16C, &this->actor.world.pos);
    Math_Vec3f_Copy(&this->unk_154, &this->actor.world.pos);
    Math_Vec3f_Copy(&this->unk_160, &this->actor.world.pos);
    Actor_SetScale(&this->actor, 0.005f);
    this->actor.update = ref_func_80A4F16C;
    this->actor.draw = ref_func_80A4F4C8;
    this->actionFunc = ref_func_80A4EF74;
}
