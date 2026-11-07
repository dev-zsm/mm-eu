// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test.h"

void ref_func_80862CBC(EnTestStruct* arg0, Vec3f* arg1) {
    EnTestStruct* ptr;
    s32 i;

    for (i = 0; i < 20; i++) {
        ptr = &arg0[i];

        if (!ptr->unk_00) {
            s16 sp26 = Rand_ZeroOne() * 0xFFFF;
            f32 sp20;

            ptr->unk_00 = true;

            ptr->unk_08.x = (Math_CosS(sp26) * 20.0f) + arg1->x;
            ptr->unk_08.y = arg1->y;
            ptr->unk_08.z = (Math_SinS(sp26) * 20.0f) + arg1->z;

            sp20 = Rand_ZeroOne();

            ptr->unk_14.x = Math_CosS(sp26) * 13.0f * sp20;
            ptr->unk_14.y = (Rand_ZeroOne() * 5.0f) + 8.0f;
            ptr->unk_14.z = (Math_SinS(sp26) * 13.0f) * sp20;

            ptr->unk_20.x = 0.0f;
            ptr->unk_20.z = 0.0f;
            ptr->unk_20.y = -2.0f;

            ptr->unk_2C = (Rand_ZeroOne() * 0.0004f) + 0.0004f;

            ptr->unk_30.x = Rand_ZeroOne() * 0x7FFE;
            ptr->unk_30.y = Rand_ZeroOne() * 0x7FFE;
            ptr->unk_30.z = Rand_ZeroOne() * 0x7FFE;

            ptr->unk_36.x = Rand_ZeroOne() * 0x2000;
            ptr->unk_36.y = Rand_ZeroOne() * 0x2000;
            ptr->unk_36.z = Rand_ZeroOne() * 0x2000;

            ptr->unk_04 = 10;
            break;
        }
    }
}
