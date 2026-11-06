// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

EnKusa2UnkBssSubStruct2* ref_func_80A5C0B8(EnKusa2UnkBssStruct* arg0) {
    s32 i;
    EnKusa2UnkBssSubStruct2* phi_v1 = &arg0->unk_0480[0];

    for (i = 1; i < ARRAY_COUNT(ref_D_80A5F1C0.unk_0480); i++) {
        EnKusa2UnkBssSubStruct2* iter = &arg0->unk_0480[i];

        if (iter->unk_2C < phi_v1->unk_2C) {
            phi_v1 = iter;

            if (phi_v1->unk_2C <= 0) {
                break;
            }
        }
    }

    return phi_v1;
}
