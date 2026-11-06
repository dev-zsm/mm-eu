// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hugebombiwa.h"

void ref_func_80A55310(ObjHugebombiwa* this) {
    s32 i;
    EnHugebombiwaStruct* ptr;
    s32 pad;
    f32 temp_f20;
    f32 temp_f20_2;
    s16 phi_s2;
    Vec3f sp84;

    Matrix_Push();
    Matrix_RotateYS(this->actor.shape.rot.y, MTXMODE_NEW);

    for (i = 0, phi_s2 = 0x1000; i < ARRAY_COUNT(this->unk_190); i++, phi_s2 += 0x4000) {
        ptr = &this->unk_190[i];

        temp_f20 = (Rand_ZeroOne() * 0.09f) + 0.016f;
        ptr->unk_00.x = ((Rand_ZeroOne() * 0.1f) + 0.95f) * temp_f20;
        ptr->unk_00.y = ((Rand_ZeroOne() * 0.1f) + 0.95f) * temp_f20;
        ptr->unk_00.z = ((Rand_ZeroOne() * 0.1f) + 0.95f) * temp_f20;

        temp_f20_2 = (Rand_ZeroOne() * 85.0f) + 77.0f;
        sp84.x = Math_SinS(phi_s2) * temp_f20_2;
        sp84.y = (i + 1) * 14.0f;
        sp84.z = fabsf(Math_CosS(phi_s2)) * temp_f20_2;
        Matrix_MultVec3f(&sp84, &ptr->unk_0C);

        ptr->unk_0C.x += this->actor.world.pos.x;
        ptr->unk_0C.y += this->actor.world.pos.y;
        ptr->unk_0C.z += this->actor.world.pos.z;

        ptr->unk_18 = (i * 1.04f) + 2.4f;

        ptr->unk_1C.x = phi_s2;
        ptr->unk_1C.y = Rand_Next() >> 0x10;
        ptr->unk_1C.z = 0;

        ptr->unk_22 = Rand_ZeroFloat(5000.0f);
        ptr->unk_24 = 0;
    }

    this->unk_4B0 = 0;
    this->unk_4B2 = 100;
    Matrix_Pop();
    this->actionFunc = ref_func_80A55564;
}
