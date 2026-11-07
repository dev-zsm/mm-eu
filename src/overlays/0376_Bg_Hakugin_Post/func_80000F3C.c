// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

void ref_func_80A9BC0C(BgHakuginPostUnkStruct* unkStruct) {
    s32 i;

    if (unkStruct->unk_1924) {
        unkStruct->unk_1924 = false;

        for (i = 0; i < ARRAY_COUNT(unkStruct->unk_02A4); i++) {
            BgHakuginPostUnkStruct2* unkStruct2 = &unkStruct->unk_02A4[i];

            if (unkStruct2->unk_2C > 0) {
                unkStruct2->unk_10.y = unkStruct2->unk_10.y + -4.0f;
                Math_Vec3f_Scale(&unkStruct2->unk_10, unkStruct2->unk_1C);
                unkStruct2->unk_04.x += unkStruct2->unk_10.x;
                unkStruct2->unk_04.y += unkStruct2->unk_10.y;
                unkStruct2->unk_04.z += unkStruct2->unk_10.z;
                unkStruct2->unk_20.x += unkStruct2->unk_26;
                unkStruct2->unk_20.y += unkStruct2->unk_28;
                unkStruct2->unk_20.z += unkStruct2->unk_2A;
                unkStruct2->unk_2C--;
                unkStruct->unk_1924 = true;
            }
        }
    }
}
