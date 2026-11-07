// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_tanron1.h"

void ref_func_80BB4E50(EnTanron1Struct* arg0, Vec3f* arg1, s16 arg2) {
    s16 i;

    for (i = 0; i < 200; i++, arg0++) {
        if (arg0->unk_24 == 0) {
            arg0->unk_24 = 1;
            arg0->unk_2C = 0.0f;
            arg0->unk_00 = *arg1;
            arg0->unk_18 = arg0->unk_1C = 0;
            arg0->unk_1A = arg2;
            arg0->unk_26 = Rand_ZeroFloat(100.0f);
            arg0->unk_28 = 0;
            if (Rand_ZeroOne() < 0.5f) {
                arg0->unk_2A = 0xC00;
            } else {
                arg0->unk_2A = -0xC00;
            }
            break;
        }
    }
}
