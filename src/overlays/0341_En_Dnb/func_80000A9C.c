// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_dnb.h"

s32 ref_func_80A5086C(EnDnbUnkStruct* arg0) {
    s32 count = 0;
    s32 i;

    for (i = 0; i < 256; i++, arg0++) {
        if (arg0->isEnabled == true) {
            count++;
            if (arg0->unk_01 != 0) {
                arg0->unk_0C.x += arg0->unk_18.x;
                arg0->unk_0C.y += arg0->unk_18.y;
                arg0->unk_0C.z += arg0->unk_18.z;
                arg0->unk_01 -= 1;
            } else {
                arg0->isEnabled = false;
            }
        }
    }

    return count;
}
