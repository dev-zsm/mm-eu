// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test.h"

void ref_func_80862B70(EnTestStruct* arg0) {
    s32 i;

    for (i = 0; i < 20; i++) {
        EnTestStruct* ptr = &arg0[i];

        ptr->unk_00 = false;
        ptr->unk_04 = 0;
        ptr->unk_08.x = 0.0f;
        ptr->unk_08.y = 0.0f;
        ptr->unk_08.z = 0.0f;
        ptr->unk_14.x = 0.0f;
        ptr->unk_14.y = 0.0f;
        ptr->unk_14.z = 0.0f;
        ptr->unk_20.x = 0.0f;
        ptr->unk_20.y = 0.0f;
        ptr->unk_20.z = 0.0f;
        ptr->unk_2C = 0.001f;
        ptr->unk_30.x = 0;
        ptr->unk_30.y = 0;
        ptr->unk_30.z = 0;
        ptr->unk_36.x = 0;
        ptr->unk_36.y = 0;
        ptr->unk_36.z = 0;
    }
}
