// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_usiyane.h"

void ref_func_80C07F30(ObjUsiyane* this, PlayState* play) {
    s32 i;
    s32 j;
    Vec3f sp94;

    for (i = 0; i < ARRAY_COUNT(this->unk_168[0]); i++) {
        for (j = 0; j < ARRAY_COUNT(this->unk_168); j++) {
            if (i != (ARRAY_COUNT(this->unk_168[0]) - 1)) {
                ref_func_80C07DFC(&this->unk_710[i], &ref_D_80C08660[i].rot, &this->unk_710[i + 1], &ref_D_80C08660[i + 1].rot, j,
                              10, &this->unk_168[j][i].unk_00, &this->unk_168[j][i].unk_18);
            } else {
                ref_func_80C07DFC(&this->unk_710[i], &ref_D_80C08660[i].rot, &this->unk_710[0], &ref_D_80C08660[0].rot, j, 10,
                              &this->unk_168[j][i].unk_00, &this->unk_168[j][i].unk_18);
            }
            ref_func_800B12F0(play, &this->unk_168[j][i].unk_00, &gZeroVec3f, &gZeroVec3f, 100, 30, 7);

            this->unk_168[j][i].unk_18.y = (s32)Rand_Next() >> 0x10;

            sp94.x = this->unk_168[j][i].unk_00.x - this->unk_708;
            sp94.y = 0.0f;
            sp94.z = this->unk_168[j][i].unk_00.z - this->unk_70C;
            Math3D_Normalize(&sp94);

            sp94.x *= 5.0f;
            sp94.y = 19.0f;
            sp94.z *= 5.0f;

            this->unk_168[j][i].unk_0C = sp94;

            this->unk_168[j][i].unk_1E.x = Rand_Centered() * 4000.0f;
            this->unk_168[j][i].unk_1E.y = Rand_Centered() * 4000.0f;
            this->unk_168[j][i].unk_1E.z = Rand_Centered() * 4000.0f;
        }
    }

    Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_HOUSE_BROKEN);
    this->unk_740 = 0;
    this->unk_744 |= 4;
}
