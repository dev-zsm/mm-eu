// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A2319C(ObjIceblock* this, f32 arg1) {
    s32 i;
    s16 temp_s1 = Rand_Next() >> 0x10;
    s16 temp_s2 = Rand_Next() >> 0x10;
    ObjIceBlockUnkStruct* ptr;

    for (i = 0; i < ARRAY_COUNT(this->unk_1B4); i++) {
        ptr = &this->unk_1B4[i];
        temp_s1 += Rand_S16Offset(2700, 10000);
        temp_s2 += Rand_S16Offset(2700, 10000);
        ptr->unk_00 = temp_s1;
        ptr->unk_02 = temp_s2;
        ptr->unk_04 = ((Rand_ZeroOne() * 0.2f) + 0.9f) * arg1;
        ptr->unk_08 = ((Rand_ZeroOne() * 0.2f) + 0.9f) * arg1;
        ptr->unk_0C = ((Rand_ZeroOne() * 0.2f) + 0.9f) * arg1;
    }
}
