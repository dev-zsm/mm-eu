// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_goron_oyu.h"

void BgGoronOyu_SpawnEffects(BgGoronOyu* this, PlayState* play) {
    s16 scale;
    Vec3f pos1;
    Vec3f pos2;
    CollisionPoly* poly;
    s32 pad;

    if ((play->state.frames % 4) == 0) {
        Vec3f vel1;
        Vec3f vel2;

        pos1.x = this->dyna.actor.world.pos.x;
        pos1.y = this->dyna.actor.world.pos.y + 100.0f;
        pos1.z = this->dyna.actor.world.pos.z;
        vel1.x = 0.0f;
        vel1.y = 2.5f;
        vel1.z = 0.0f;
        scale = -200 - (s32)(Rand_ZeroOne() * 50.0f);

        if (BgCheck_EntityRaycastFloor2(play, &play->colCtx, &poly, &pos1) < this->waterBoxPos.y) {
            pos1.y = this->waterBoxPos.y + 10.0f;
            EffectSsIceSmoke_Spawn(play, &pos1, &vel1, &gZeroVec3f, scale);
        }
        pos2.x = (Rand_ZeroOne() * this->waterBoxXLength) + this->waterBoxPos.x;
        pos2.y = this->waterBoxPos.y + 100.0f;
        pos2.z = (Rand_ZeroOne() * this->waterBoxZLength) + this->waterBoxPos.z;
        vel2.x = 0.0f;
        vel2.y = 0.5f;
        vel2.z = 0.0f;
        scale = -200 - (s32)(Rand_ZeroOne() * 50.0f);

        if (BgCheck_EntityRaycastFloor2(play, &play->colCtx, &poly, &pos2) < this->waterBoxPos.y) {
            pos2.y = this->waterBoxPos.y + 10.0f;
            EffectSsIceSmoke_Spawn(play, &pos2, &vel2, &gZeroVec3f, scale);
        }
    }
}
