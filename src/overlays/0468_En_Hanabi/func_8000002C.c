// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_hanabi.h"

void ref_func_80B22C2C(EnHanabiStruct* arg0, s32 arg1) {
    arg0->unk_01 = (s32)Rand_ZeroFloat(20.0f) + 60;
    arg0->unk_02 = arg1;
    arg0->unk_14.x = 0.7f;
}
