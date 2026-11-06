// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_dhouse.h"

void ref_func_80B13474(ObjDhouse* this, PlayState* play, Vec3f* arg2) {
    s32 i;
    Vec3f sp88;
    ObjDhouseStruct2* ptr2;

    for (i = 0; i < 5; i++) {
        ptr2 = &this->unk_240[ref_func_80B12D78(this)];

        ptr2->unk_00.x = Rand_ZeroOne() - 0.5f;
        ptr2->unk_00.y = Rand_ZeroOne();
        ptr2->unk_00.z = Rand_ZeroOne() - 0.5f;

        ptr2->unk_0C.x = ptr2->unk_00.x * 18.0f;
        ptr2->unk_0C.y = ptr2->unk_00.y * 23.0f;
        ptr2->unk_0C.z = ptr2->unk_00.z * 18.0f;

        ptr2->unk_00.x = (ptr2->unk_00.x * 40.0f) + arg2->x;
        ptr2->unk_00.y = ((ptr2->unk_00.y - 0.4f) * 20.0f) + arg2->y;
        ptr2->unk_00.z = (ptr2->unk_00.z * 40.0f) + arg2->z;

        ptr2->unk_1C.x = Rand_Next() >> 0x10;
        ptr2->unk_1C.y = Rand_Next() >> 0x10;
        ptr2->unk_1C.z = Rand_Next() >> 0x10;

        ptr2->unk_22 = (Rand_Next() >> 0x12) - 0x1FFF;
        ptr2->unk_24 = (Rand_Next() >> 0x13) - 0xFFF;
        ptr2->unk_26 = (Rand_Next() >> 0x12) - 0x1FFF;

        ptr2->unk_28 = 40;
        ptr2->unk_18 = (Rand_ZeroOne() * 0.07f) + 0.003f;
        ptr2->unk_29 = 0;

        sp88.x = ((Rand_ZeroOne() * 70.0f) - 35.0f) + ptr2->unk_00.x;
        sp88.y = (Rand_ZeroOne() * 60.0f) + ptr2->unk_00.y;
        sp88.z = ((Rand_ZeroOne() * 70.0f) - 35.0f) + ptr2->unk_00.z;

        ref_func_800B1210(play, &sp88, &gZeroVec3f, &ref_D_80B13FA8, (s32)(Rand_ZeroOne() * 80.0f) + 20,
                      (s32)(Rand_ZeroOne() * 90.0f) + 40);
    }
}
