// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_hanabi.h"

void ref_func_80B22E0C(EnHanabiStruct* arg0) {
    s32 i;

    for (i = 0; i < 400; i++, arg0++) {
        if (arg0->unk_00 == 1) {
            arg0->unk_08.x += arg0->unk_20.x;
            arg0->unk_08.y += arg0->unk_20.y;
            arg0->unk_08.z += arg0->unk_20.z;

            arg0->unk_20.x *= arg0->unk_14.x;
            arg0->unk_20.z *= arg0->unk_14.x;
            arg0->unk_20.y *= arg0->unk_14.x;
            arg0->unk_20.y -= 1.0f;

            arg0->unk_20.x += Rand_CenteredFloat(0.8f);
            arg0->unk_20.y += Rand_CenteredFloat(0.8f);
            arg0->unk_20.z += Rand_CenteredFloat(0.8f);

            if (arg0->unk_01 > 0) {
                arg0->unk_01--;
            } else {
                arg0->unk_00 = 0;
            }
        }
    }
}
