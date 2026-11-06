// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

f32 ref_func_80A9B244(BgHakuginPostUnkStruct* unkStruct) {
    s32 i;
    f32 ret = 0.0f;

    for (i = 0; i < unkStruct->count; i++) {
        ret += ref_D_80A9D880[unkStruct->unk_0000[i].unk_00].unk_00;
    }

    return ret;
}
