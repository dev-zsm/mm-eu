// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_mir_ray3.h"

void ref_func_80B9E544(MirRay3* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    MtxF* shieldMtx = &player->shieldMf;
    f32 temp_f0;

    if (this->unk_210 & 2) {
        temp_f0 = sqrtf(SQ(shieldMtx->mf[2][0]) + SQ(shieldMtx->mf[2][1]) + SQ(shieldMtx->mf[2][2]));
        if (temp_f0 == 0.0f) {
            this->unk_260 = 1.0f;
        } else {
            this->unk_260 = 1.0f / temp_f0;
        }
        Math_ApproachF(&this->unk_214, 1.0f, 0.5f, 0.25f);
    }
}
