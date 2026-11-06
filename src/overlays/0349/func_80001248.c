// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_water_effect.h"

void ref_func_80A599E8(EnWaterEffect* this, Vec3f* arg1, u8 arg2) {
    s16 i;
    EnWaterEffectStruct* ptr = &this->unk_144[0];

    for (i = 0; i < ARRAY_COUNT(this->unk_144); i++, ptr++) {
        if (ptr->unk_00 == 0) {
            ptr->unk_00 = 4;
            ptr->unk_04 = *arg1;

            ptr->unk_1C = sZeroVec;
            ptr->unk_10 = sZeroVec;

            if ((arg2 == 0) || (arg2 == 2)) {
                ptr->unk_1C.y = -1.0f;
            }

            if (arg2 >= 2) {
                if (arg2 == 2) {
                    ptr->unk_10.x = Rand_CenteredFloat(10.0f);
                    ptr->unk_10.y = Rand_ZeroFloat(3.0f) + 5.0f;
                    ptr->unk_10.z = Rand_CenteredFloat(10.0f);
                }
                ptr->unk_2C.z = 0.0017f;
                ptr->unk_2C.x = 0.003f;
                ptr->unk_2C.y = 0.0018f;
            } else {
                ptr->unk_2C.z = 0.003f;
                ptr->unk_2C.x = 0.003f;
                ptr->unk_2C.y = 0.003f;
            }
            ptr->unk_38 = 255.0f;
            ptr->unk_28 = Rand_ZeroFloat(0x10000);
            ptr->unk_3C = 255;
            ptr->unk_01 = Rand_ZeroFloat(200.0f);
            ptr->unk_2A = arg2;
            break;
        }
    }
}
