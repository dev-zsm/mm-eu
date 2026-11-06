// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_water_effect.h"

void ref_func_80A587A0(EnWaterEffect* this, Vec3f* arg1, u8 arg2) {
    s16 i;
    EnWaterEffectStruct* ptr = &this->unk_144[0];

    for (i = 0; i < ARRAY_COUNT(this->unk_144) / 2; i++, ptr++) {
        if (!ptr->unk_00) {
            ptr->unk_00 = true;
            ptr->unk_04 = *arg1;
            ptr->unk_10 = sZeroVec;
            ptr->unk_1C = sZeroVec;
            ptr->unk_2C.x = 0.1f;
            ptr->unk_2C.y = 0.0f;
            ptr->unk_2C.z = Rand_ZeroFloat(M_PIf * 2);
            ptr->unk_01 = Rand_ZeroFloat(100.0f);
            ptr->unk_2A = arg2;
            break;
        }
    }
}
