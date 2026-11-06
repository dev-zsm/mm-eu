// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bombiwa.h"

void ref_func_8093A080(ObjBombiwa* this) {
    ObjBombiwaStruct* ptr;
    s16 phi_s2;
    s32 i;

    for (i = 0, phi_s2 = 0; i < ARRAY_COUNT(this->unk_190); i++, phi_s2 += 0x4000) {
        ptr = &this->unk_190[i];

        ptr->unk_00 = (Rand_ZeroOne() * 0.1f) + 0.05f;

        ptr->unk_04.x = (Math_SinS(phi_s2) * 50.0f) + this->actor.world.pos.x;
        ptr->unk_04.y = ((i + 1) * 31.0f) + this->actor.world.pos.y;
        ptr->unk_04.z = (Math_CosS(phi_s2) * 50.0f) + this->actor.world.pos.z;

        ptr->unk_10 = i + 3.0f;
        ptr->unk_14.x = phi_s2;
        ptr->unk_14.y = Rand_Next() >> 0x10;
        ptr->unk_14.z = 0;
        ptr->unk_1A = 0;
    }

    this->unk_200 = 0;
    this->unk_201 = 80;
    this->actionFunc = ref_func_8093A1F0;
}
