// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5C7F0(EnKusa2UnkBssStruct* arg0, EnKusa2UnkBssSubStruct* arg1) {
    if (arg1->unk_26 > 0) {
        arg1->unk_26--;
        arg1->unk_28(arg1);
        if (arg1->unk_26 >= arg1->unk_24) {
            arg1->unk_2C += arg1->unk_34;
            arg1->unk_3C += arg1->unk_40;
            arg1->unk_58 += arg1->unk_5C;
        } else {
            arg1->unk_2C -= arg1->unk_38;
            if (arg1->unk_2C < 0.0f) {
                arg1->unk_2C = 0.0f;
            }
            arg1->unk_3C -= arg1->unk_44;
            arg1->unk_58 -= arg1->unk_60;
            if (arg1->unk_58 < 0.0f) {
                arg1->unk_58 = 0.0f;
            }
        }
        arg1->unk_30 = arg1->unk_2C * 0.5f;
        arg1->unk_50 = 0x8000 / arg1->unk_3C;
        arg1->unk_54 = 0x8000 / (arg1->unk_48 - arg1->unk_3C);
    }
}
