// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball.h"

void ref_func_80B03E2C(ObjSnowball* this, PlayState* play) {
    ObjSnowballStruct* ptr;
    s32 i;

    this->unk_1A8[0].unk_1C.y = this->actor.yawTowardsPlayer - 0x4000;
    this->unk_1A8[0].unk_24 = Rand_ZeroOne() * -600.0f;
    this->unk_1A8[1].unk_1C.y = this->actor.yawTowardsPlayer + 0x4000;
    this->unk_1A8[1].unk_24 = Rand_ZeroOne() * 600.0f;

    for (i = 0; i < ARRAY_COUNT(this->unk_1A8); i++) {
        ptr = &this->unk_1A8[i];
        ptr->unk_00.x = this->actor.home.pos.x;
        ptr->unk_00.y = this->actor.home.pos.y + (61.0f * this->unk_20C);
        ptr->unk_00.z = this->actor.home.pos.z;

        ptr->unk_0C = Math_SinS(ptr->unk_1C.y) * (Rand_ZeroOne() + 5.0f);
        ptr->unk_10 = (Rand_ZeroOne() * 11.0f) + 20.0f;
        ptr->unk_14 = Math_CosS(ptr->unk_1C.y) * (Rand_ZeroOne() + 5.0f);

        ptr->unk_1C.x = 0;
        ptr->unk_1C.z = 0;

        ptr->unk_22 = (s32)(Rand_ZeroOne() * 400.0f) + 1100;
        ptr->unk_26 = Rand_ZeroOne() * -600.0f;
        ptr->unk_2D = 0;
        ptr->unk_2C = 0;
    }
}
