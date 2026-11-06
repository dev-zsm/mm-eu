// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_object_kankyo.h"

void ref_func_808DCDB4(ObjectKankyo* this, PlayState* play) {
    s16 i;
    f32 magnitude;
    f32 temp_80;
    f32 temp_120;
    f32 spAC;
    f32 spA8;
    f32 spA4;
    f32 spA0;
    f32 sp9C;
    f32 x;
    f32 y;
    f32 z;
    f32 temp_f18;
    f32 temp_f20;
    f32 temp_f26;
    f32 temp_f28;

    if (this->unk_114C < 0x80) {
        this->unk_114C++;
    }

    x = play->view.at.x - play->view.eye.x;
    y = play->view.at.y - play->view.eye.y;
    z = play->view.at.z - play->view.eye.z;

    magnitude = sqrtf(SQ(x) + SQ(y) + SQ(z));

    spAC = x / magnitude;
    spA8 = y / magnitude;
    spA4 = z / magnitude;

    temp_80 = 80.0f;
    temp_120 = 120.0f;

    for (i = 0; i < this->unk_114C; i++) {
        switch (this->unk_14C[i].unk_1C) {
            case 0:
                this->unk_14C[i].unk_00 = play->view.eye.x + (spAC * 120.0f);
                this->unk_14C[i].unk_04 = play->view.eye.y + (spA8 * 120.0f);
                this->unk_14C[i].unk_08 = play->view.eye.z + (spA4 * 120.0f);
                this->unk_14C[i].unk_0C = (Rand_ZeroOne() - 0.5f) * (temp_120 * 2.0f);
                if ((i % 2) == 0) {
                    this->unk_14C[i].unk_10 = -100.0f;
                } else {
                    this->unk_14C[i].unk_10 = 100.0f;
                }
                this->unk_14C[i].unk_14 = (Rand_ZeroOne() - 0.5f) * (temp_120 * 2.0f);
                this->unk_14C[i].unk_18 = Rand_ZeroOne() + 0.2f;
                this->unk_14C[i].unk_1C++;
                break;

            case 1:
                temp_f26 = play->view.eye.x + (spAC * 120.0f);
                temp_f28 = play->view.eye.y + (spA8 * 120.0f);
                temp_f18 = play->view.eye.z + (spA4 * 120.0f);

                magnitude = sqrtf((f32)SQ(play->envCtx.windDirection.x) + SQ(play->envCtx.windDirection.y) +
                                  SQ(play->envCtx.windDirection.z));
                if (magnitude == 0.0f) {
                    magnitude = 0.001f;
                }

                spA0 = -play->envCtx.windDirection.x / magnitude;
                sp9C = -play->envCtx.windDirection.z / magnitude;

                if (i == 0) {
                    this->unk_144 += 0.049999997f * Rand_ZeroOne();
                    this->unk_148 += 0.049999997f * Rand_ZeroOne();
                }
                temp_f20 = play->envCtx.windSpeed / 120.0f;
                temp_f20 = CLAMP(temp_f20, 0.0f, 1.0f);

                this->unk_14C[i].unk_0C += sinf((this->unk_144 + i) * 0.01f) + (spA0 * 10.0f * temp_f20);
                this->unk_14C[i].unk_14 += cosf((this->unk_148 + i) * 0.01f) + (sp9C * 10.0f * temp_f20);

                if ((i % 2) == 0) {
                    this->unk_14C[i].unk_10 += this->unk_14C[i].unk_18;
                    if ((this->unk_14C[i].unk_04 + this->unk_14C[i].unk_10) > (play->view.eye.y + 100.0f)) {
                        this->unk_14C[i].unk_1C = 0;
                    }
                } else {
                    this->unk_14C[i].unk_10 -= this->unk_14C[i].unk_18;
                    if ((this->unk_14C[i].unk_04 + this->unk_14C[i].unk_10) < (play->view.eye.y - 100.0f)) {
                        this->unk_14C[i].unk_1C = 0;
                    }
                }

                if (((this->unk_14C[i].unk_00 + this->unk_14C[i].unk_0C) - temp_f26) > temp_80) {
                    this->unk_14C[i].unk_00 = temp_f26 - temp_80;
                }

                if (((this->unk_14C[i].unk_00 + this->unk_14C[i].unk_0C) - temp_f26) < -temp_80) {
                    this->unk_14C[i].unk_00 = temp_f26 + temp_80;
                }

                if (((this->unk_14C[i].unk_04 + this->unk_14C[i].unk_10) - temp_f28) > temp_80) {
                    this->unk_14C[i].unk_04 = temp_f28 - temp_80;
                }

                if (((this->unk_14C[i].unk_04 + this->unk_14C[i].unk_10) - temp_f28) < -temp_80) {
                    this->unk_14C[i].unk_04 = temp_f28 + temp_80;
                }

                if (((this->unk_14C[i].unk_08 + this->unk_14C[i].unk_14) - temp_f18) > temp_80) {
                    this->unk_14C[i].unk_08 = temp_f18 - temp_80;
                }

                if (((this->unk_14C[i].unk_08 + this->unk_14C[i].unk_14) - temp_f18) < -temp_80) {
                    this->unk_14C[i].unk_08 = temp_f18 + temp_80;
                }
                break;
        }
    }
}
