// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_chikuwa.h"

void ref_func_809B17D0(PlayState* play, ObjChikuwa* this, Vec3f* arg2) {
    ObjChikuwaStruct2* temp_s0;
    f32 var_fs2;
    f32 temp;
    s32 i;

    for (i = 0, var_fs2 = -78.75f; i < 8; var_fs2 += 22.5f) {
        temp_s0 = &this->unk_2A4[this->unk_9A4];

        temp_s0->unk_00.x = (Rand_ZeroOne() * 0.05f) + 0.01f;
        temp_s0->unk_00.y = (Rand_ZeroOne() * 0.16f) + 0.04f;
        temp_s0->unk_00.z = (Rand_ZeroOne() * 0.05f) + 0.01f;

        temp_s0->unk_0C.x = (Math_CosS(this->dyna.actor.shape.rot.y) * var_fs2) + arg2->x;
        temp_s0->unk_0C.y = arg2->y;
        temp_s0->unk_0C.z = (Math_SinS(this->dyna.actor.shape.rot.y) * var_fs2) + arg2->z;

        temp_s0->unk_18 = (2.0f * Rand_ZeroOne()) - 1.0f;
        temp_s0->unk_1C = (Rand_ZeroOne() * 4.0f) - 1.0f;
        temp_s0->unk_20 = (2.0f * Rand_ZeroOne()) - 1.0f;

        temp = Math3D_Vec3fMagnitude(&temp_s0->unk_00);
        temp_s0->unk_24 = (-Rand_ZeroOne() * 0.5f) - temp * 25.0f;

        temp_s0->unk_28.x = this->dyna.actor.shape.rot.x;
        temp_s0->unk_28.y = this->dyna.actor.shape.rot.y;
        temp_s0->unk_28.z = this->dyna.actor.shape.rot.z;

        temp_s0->unk_2E.x = (Rand_ZeroOne() - 0.5f) * 5000.0f;
        temp_s0->unk_2E.y = (Rand_ZeroOne() - 0.5f) * 5000.0f;
        temp_s0->unk_2E.z = (Rand_ZeroOne() - 0.5f) * 5000.0f;

        temp_s0->unk_34 = 80;
        ref_func_800B1210(play, &temp_s0->unk_0C, &ref_D_809B1FDC, &ref_D_809B1FD0, (Rand_ZeroOne() * 60.0f) + 80.0f,
                      (Rand_ZeroOne() * 30.0f) + 60.0f);
        this->unk_9A4 = (this->unk_9A4 + 1) & 0x1F;
        i++;
    }
}
