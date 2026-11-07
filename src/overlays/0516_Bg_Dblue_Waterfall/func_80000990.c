// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_waterfall.h"

void ref_func_80B84610(BgDblueWaterfall* this, PlayState* play) {
    s32 pad;
    Player* player = GET_PLAYER(play);
    Vec3f sp34;

    if (this->unk_1A7 <= 0) {
        this->unk_1A7 = 16;
    } else {
        this->unk_1A7 -= (s8)(Rand_Next() >> 0x1F);
    }

    if (this->unk_1A7 >= 6) {
        this->unk_1A8 += Rand_ZeroOne() * 0.1f;
        this->unk_1A8 = CLAMP_MAX(this->unk_1A8, 0.5f);
    } else {
        this->unk_1A8 -= Rand_ZeroOne() * 0.2f;
        this->unk_1A8 = CLAMP_MAX(this->unk_1A8, -0.5f);
    }

    Matrix_Push();
    Matrix_RotateYS(BINANG_ADD(this->actor.yawTowardsPlayer, 0x4000), MTXMODE_NEW);
    Matrix_MultVecZ(this->unk_1A8, &sp34);
    Matrix_Pop();

    player->actor.world.pos.x += sp34.x;
    player->actor.world.pos.z += sp34.z;

    {
        s32 requiredScopeTemp;

        player->pushedSpeed = 8.0f;
        player->pushedYaw = this->actor.yawTowardsPlayer;
    }
}
