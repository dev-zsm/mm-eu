// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_solder_srch_ball.h"

void EffectSsSolderSrchBall_Update(PlayState* play, u32 index, EffectSs* this) {
    s32 pad;
    f32 diffX;
    f32 diffY;
    f32 diffZ;
    s16* playerDetected = (s16*)this->actor;
    Player* player = GET_PLAYER(play);

    diffX = player->actor.world.pos.x - this->pos.x;
    diffY = player->actor.world.pos.y - this->pos.y;
    diffZ = player->actor.world.pos.z - this->pos.z;

    if (this->rFlags >= SOLDERSRCHBALL_SMALL_DETECT_RADIUS) {
        if ((sqrtf(SQ(diffX) + SQ(diffZ)) < 10.0f) && (sqrtf(SQ(diffY)) < 10.0f)) {
            *playerDetected = true;
        }
    } else if (!BgCheck_SphVsFirstWall(&play->colCtx, &this->pos, 30.0f)) {
        if ((sqrtf(SQ(diffX) + SQ(diffZ)) < 40.0f) && (sqrtf(SQ(diffY)) < 80.0f)) {
            *playerDetected = true;
        }
    } else if (this->life > 1) {
        this->life = 1;
    }
}
