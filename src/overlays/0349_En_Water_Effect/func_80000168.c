// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_water_effect.h"

void ref_func_80A58908(EnWaterEffect* this, Vec3f* arg1, Vec3f* arg2, u8 arg3) {
    Vec3f sp2C = { 0.0f, -1.0f, 0.0f };
    EnWaterEffectStruct* ptr = &this->unk_144[0];
    s16 i;

    for (i = 0; i < ARRAY_COUNT(this->unk_144) / 2; i++, ptr++) {
        if (ptr->unk_00 == 0) {
            ptr->unk_00 = 2;
            ptr->unk_04 = *arg1;
            ptr->unk_10 = *arg2;
            ptr->unk_1C = sp2C;
            ptr->unk_2C.y = Rand_ZeroFloat(0.02f) + 0.02f;
            ptr->unk_2C.x = ptr->unk_2C.y;
            ptr->unk_2C.z = Rand_ZeroFloat(M_PIf * 2);
            ptr->unk_01 = Rand_ZeroFloat(100.0f);
            ptr->unk_2A = arg3;
            break;
        }
    }
}
