// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball2.h"

void ref_func_80B3A0D8(ObjSnowball2* this) {
    this->unk_1AC = 60;
    this->actor.colChkInfo.mass = 180;
    this->unk_1A8 = Rand_S16Offset(-5000, 4000);
    this->unk_1AA = Rand_S16Offset(-800, 1600);
    this->actionFunc = ref_func_80B3A13C;
}
