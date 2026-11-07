// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_dhouse.h"

void ref_func_80B12E7C(ObjDhouse* this, PlayState* play, ObjDhouseStruct1* ptr, ObjDhouseStruct3* ptr3) {
    s32 i;
    Vec3f spA0;
    Vec3f sp94;
    Vec3f sp88;
    ObjDhouseStruct2* ptr2;

    Matrix_RotateYS(this->dyna.actor.shape.rot.y, MTXMODE_NEW);
    Matrix_MultVec3fXZ(&ref_D_80B13FC4, &sp94);
    sp94.y = 100.0f;
    ref_func_80B12A50(ptr, ptr3, &spA0);

    for (i = 0; i < 15; i++) {
        ptr2 = &this->unk_240[ref_func_80B12D78(this)];

        ptr2->unk_00.x = Rand_ZeroOne() - 0.5f;
        ptr2->unk_00.y = Rand_ZeroOne();
        ptr2->unk_00.z = Rand_ZeroOne() - 0.5f;

        ptr2->unk_0C.x = ptr2->unk_00.x * 24.0f;
        ptr2->unk_0C.y = ptr2->unk_00.y * 34.0f;
        ptr2->unk_0C.z = ptr2->unk_00.z * 24.0f;

        ptr2->unk_00.x = (ptr2->unk_00.x * 140.0f) + spA0.x;
        ptr2->unk_00.y = ((ptr2->unk_00.y - 0.2f) * 50.0f) + spA0.y;
        ptr2->unk_00.z = (ptr2->unk_00.z * 140.0f) + spA0.z;

        ptr2->unk_18 = (Rand_ZeroOne() * 0.057f) + 0.003f;

        ptr2->unk_1C.x = Rand_Next() >> 0x10;
        ptr2->unk_1C.y = Rand_Next() >> 0x10;
        ptr2->unk_1C.z = Rand_Next() >> 0x10;

        ptr2->unk_22 = (Rand_Next() >> 0x11) - 0x3FFF;
        ptr2->unk_24 = (Rand_Next() >> 0x13) - 0xFFF;
        ptr2->unk_26 = (Rand_Next() >> 0x12) - 0x1FFF;
        ptr2->unk_29 = 0;
        ptr2->unk_28 = 40;

        if ((i % 2) != 0) {
            sp88.x = ((Rand_ZeroOne() - 0.5f) * sp94.x) + ptr2->unk_00.x;
            sp88.y = ((Rand_ZeroOne() - 0.3f) * sp94.y) + ptr2->unk_00.y;
            sp88.z = ((Rand_ZeroOne() - 0.5f) * sp94.z) + ptr2->unk_00.z;

            ref_func_800B1210(play, &sp88, &gZeroVec3f, &ref_D_80B13FA8, (s32)(Rand_ZeroOne() * 130.0f) + 20,
                          (s32)(Rand_ZeroOne() * 140.0f) + 60);
        }
    }
}
