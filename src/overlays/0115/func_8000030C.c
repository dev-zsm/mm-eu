// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_object_kankyo.h"

void ref_func_808DC18C(ObjectKankyo* this, PlayState* play) {
    s32 pad;
    s32 pad2;
    s32 pad3;
    f32 magnitude;
    f32 y;
    f32 z;
    f32 temp_f18;
    Vec3f sp30;
    f32 x;
    f32 sp1C;

    x = play->view.at.x - play->view.eye.x;
    y = play->view.at.y - play->view.eye.y;
    z = play->view.at.z - play->view.eye.z;
    magnitude = sqrtf(SQ(x) + SQ(y) + SQ(z));

    temp_f18 = x / magnitude;
    x = z / magnitude;
    sp1C = (y / magnitude) * 120.0f;

    this->unk_14C[0].unk_00 = play->view.eye.x + (temp_f18 * 50.0f);
    this->unk_14C[0].unk_04 = play->view.eye.y + sp1C;
    this->unk_14C[0].unk_08 = play->view.eye.z + (x * 50.0f);
    this->unk_14C[1].unk_00 = play->view.eye.x + (temp_f18 * 220.0f);
    this->unk_14C[1].unk_08 = play->view.eye.z + (x * 220.0f);
    this->unk_114C = 0;
    this->unk_144 = 100.0f;

    if ((this->unk_14C[0].unk_00 < -252.0f) && (this->unk_14C[0].unk_00 > -500.0f)) {
        if ((this->unk_14C[0].unk_08 > 3820.0f) && (this->unk_14C[0].unk_08 < 4150.0f)) {
            this->unk_114C = 1;
            this->unk_144 = 400.0f;
            if (x < 0.0f) {
                this->unk_14C[0].unk_00 = -350.0f;
                this->unk_14C[0].unk_04 = play->view.eye.y + sp1C;
                this->unk_14C[0].unk_08 = 3680.0f;
                this->unk_14C[1].unk_00 = -350.0f;
                this->unk_14C[1].unk_08 = 3680.0f;
            } else {
                this->unk_14C[0].unk_00 = -350.0f;
                this->unk_14C[0].unk_04 = play->view.eye.y + sp1C;
                this->unk_14C[0].unk_08 = 4280.0f;
                this->unk_14C[1].unk_00 = -350.0f;
                this->unk_14C[1].unk_08 = 4280.0f;
            }
        }
    }

    magnitude = play->envCtx.windSpeed / 60.0f;
    magnitude = CLAMP(magnitude, 0.0f, 1.0f);

    sp30.x = play->envCtx.windDirection.x * magnitude;
    sp30.y = play->envCtx.windDirection.y + 100.0f;
    sp30.z = play->envCtx.windDirection.z * magnitude;
    this->unk_14C[2].unk_00 = 0x4000 - Math_Vec3f_Pitch(&gZeroVec3f, &sp30);
    this->unk_14C[2].unk_04 = Math_Vec3f_Yaw(&gZeroVec3f, &sp30) + 0x8000;
}
