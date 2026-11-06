// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball2.h"

void ref_func_80B39F60(ObjSnowball2* this) {
    this->actor.world.pos.y += (600.0f - this->actor.shape.yOffset) * this->actor.scale.y;
    this->unk_1AC = 4;
    this->actor.shape.yOffset = 600.0f;
    this->actionFunc = ref_func_80B39FA8;
}
