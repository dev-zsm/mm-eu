// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

BgHakuginPostUnkStruct1* ref_func_80A9B32C(BgHakuginPostUnkStruct* unkStruct, BgHakuginPostUnkStruct1* unkStruct1) {
    s32 i;

    for (i = 0; i < unkStruct->count; i++) {
        if (unkStruct1 == &unkStruct->unk_0000[i]) {
            break;
        }
    }

    i++;

    if (i < unkStruct->count) {
        return &unkStruct->unk_0000[i];
    }

    return NULL;
}
