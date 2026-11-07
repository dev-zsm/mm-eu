// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5CAF4(EnKusa2UnkBssStruct* arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(ref_D_80A5F1C0.unk_0000); i++) {
        ref_func_80A5C7F0(arg0, &arg0->unk_0000[i]);
    }

    for (i = 0; i < ARRAY_COUNT(ref_D_80A5F1C0.unk_0480); i++) {
        ref_func_80A5C918(arg0, &arg0->unk_0480[i]);
    }
}
