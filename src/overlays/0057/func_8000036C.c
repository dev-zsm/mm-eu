// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test.h"

void ref_func_80862EDC(EnTestStruct* arg0) {
    s32 i;
    EnTestStruct* ptr;

    for (i = 0; i < 20; i++) {
        ptr = &arg0[i];

        if (ptr->unk_00) {
            ptr->unk_04--;
            if (ptr->unk_04 < 0) {
                ptr->unk_00 = false;
            }

            ptr->unk_08.x += ptr->unk_14.x;
            ptr->unk_08.y += ptr->unk_14.y;
            ptr->unk_08.z += ptr->unk_14.z;

            ptr->unk_14.x += ptr->unk_20.x;
            ptr->unk_14.y += ptr->unk_20.y;
            ptr->unk_14.z += ptr->unk_20.z;

            ptr->unk_30.x += ptr->unk_36.x;
            ptr->unk_30.y += ptr->unk_36.y;
            ptr->unk_30.z += ptr->unk_36.z;
        }
    }
}
