// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_dhouse.h"

void ref_func_80B13170(ObjDhouse* this, PlayState* play, ObjDhouseStruct1* ptr, ObjDhouseStruct3* ptr3) {
    s32 i;
    Vec3f sp98;
    Vec3f sp8C;
    ObjDhouseStruct2* ptr2;

    ref_func_80B12A50(ptr, ptr3, &sp98);

    for (i = 0; i < 11; i++) {
        ptr2 = &this->unk_240[ref_func_80B12D78(this)];

        ptr2->unk_00.x = Rand_ZeroOne() - 0.5f;
        ptr2->unk_00.y = Rand_ZeroOne();
        ptr2->unk_00.z = Rand_ZeroOne() - 0.5f;

        ptr2->unk_0C.x = ptr2->unk_00.x * 23.0f;
        ptr2->unk_0C.y = (ptr2->unk_00.y * 19.0f) + 5.0f;
        ptr2->unk_0C.z = ptr2->unk_00.z * 23.0f;

        ptr2->unk_00.x = (ptr2->unk_00.x * 80.0f) + sp98.x;
        ptr2->unk_00.y = (ptr2->unk_00.y * 23.0f) + sp98.y + 15.0f;
        ptr2->unk_00.z = (ptr2->unk_00.z * 80.0f) + sp98.z;

        ptr2->unk_1C.x = Rand_Next() >> 0x10;
        ptr2->unk_1C.y = Rand_Next() >> 0x10;
        ptr2->unk_1C.z = Rand_Next() >> 0x10;

        ptr2->unk_22 = (Rand_Next() >> 0x12) - 0x1FFF;
        ptr2->unk_24 = (Rand_Next() >> 0x13) - 0xFFF;
        ptr2->unk_26 = (Rand_Next() >> 0x12) - 0x1FFF;

        ptr2->unk_28 = 40;

        if (i < 3) {
            ptr2->unk_18 = (Rand_ZeroOne() * 0.06f) + 0.12f;
            ptr2->unk_29 = 1;
        } else {
            ptr2->unk_18 = (Rand_ZeroOne() * 0.05f) + 0.003f;
            ptr2->unk_29 = 0;
        }

        if ((i % 2) != 0) {
            sp8C.x = ((Rand_ZeroOne() - 0.5f) * 160.0f) + ptr2->unk_00.x;
            sp8C.y = (Rand_ZeroOne() * 120.0f) + ptr2->unk_00.y;
            sp8C.z = ((Rand_ZeroOne() - 0.5f) * 160.0f) + ptr2->unk_00.z;

            ref_func_800B1210(play, &sp8C, &gZeroVec3f, &ref_D_80B13FA8, (s32)(Rand_ZeroOne() * 140.0f) + 20,
                          (s32)(Rand_ZeroOne() * 140.0f) + 40);
        }
    }
}
