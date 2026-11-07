// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bom_chu.h"

void EnBomChu_SpawnRipplesAndSplashes(EnBomChu* this, PlayState* play, f32 y, s32 spawnExtraRipples) {
    s32 pad;
    Vec3f pos;

    pos.x = this->actor.world.pos.x;
    pos.y = y;
    pos.z = this->actor.world.pos.z;

    EffectSsGRipple_Spawn(play, &pos, 70, 500, 0);

    if (spawnExtraRipples) {
        EffectSsGRipple_Spawn(play, &pos, 70, 500, 4);
        EffectSsGRipple_Spawn(play, &pos, 70, 500, 8);
    } else {
        pos.x -= this->axisForwards.x * 10.0f;
        pos.z -= this->axisForwards.z * 10.0f;
    }

    pos.y += 5.0f;
    EffectSsGSplash_Spawn(play, &pos, NULL, NULL, 1, 450);
}
