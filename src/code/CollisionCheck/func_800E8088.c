// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_SpawnRedBlood(struct PlayState* play, Vec3f* v) {
    static EffectSparkInit ref_D_801EE200;
    s32 effectIndex;

    ref_D_801EE200.position.x = v->x;
    ref_D_801EE200.position.y = v->y;
    ref_D_801EE200.position.z = v->z;
    ref_D_801EE200.uDiv = 5;
    ref_D_801EE200.vDiv = 5;
    ref_D_801EE200.colorStart[0].r = 128;
    ref_D_801EE200.colorStart[0].g = 0;
    ref_D_801EE200.colorStart[0].b = 64;
    ref_D_801EE200.colorStart[0].a = 255;
    ref_D_801EE200.colorStart[1].r = 128;
    ref_D_801EE200.colorStart[1].g = 0;
    ref_D_801EE200.colorStart[1].b = 64;
    ref_D_801EE200.colorStart[1].a = 255;
    ref_D_801EE200.colorStart[2].r = 255;
    ref_D_801EE200.colorStart[2].g = 128;
    ref_D_801EE200.colorStart[2].b = 0;
    ref_D_801EE200.colorStart[2].a = 255;
    ref_D_801EE200.colorStart[3].r = 255;
    ref_D_801EE200.colorStart[3].g = 128;
    ref_D_801EE200.colorStart[3].b = 0;
    ref_D_801EE200.colorStart[3].a = 255;
    ref_D_801EE200.colorEnd[0].r = 64;
    ref_D_801EE200.colorEnd[0].g = 0;
    ref_D_801EE200.colorEnd[0].b = 32;
    ref_D_801EE200.colorEnd[0].a = 0;
    ref_D_801EE200.colorEnd[1].r = 64;
    ref_D_801EE200.colorEnd[1].g = 0;
    ref_D_801EE200.colorEnd[1].b = 32;
    ref_D_801EE200.colorEnd[1].a = 0;
    ref_D_801EE200.colorEnd[2].r = 128;
    ref_D_801EE200.colorEnd[2].g = 0;
    ref_D_801EE200.colorEnd[2].b = 64;
    ref_D_801EE200.colorEnd[2].a = 0;
    ref_D_801EE200.colorEnd[3].r = 128;
    ref_D_801EE200.colorEnd[3].g = 0;
    ref_D_801EE200.colorEnd[3].b = 64;
    ref_D_801EE200.colorEnd[3].a = 0;
    ref_D_801EE200.timer = 0;
    ref_D_801EE200.duration = 16;
    ref_D_801EE200.speed = 8.0f;
    ref_D_801EE200.gravity = -1.0f;

    Effect_Add(play, &effectIndex, EFFECT_SPARK, 0, 1, &ref_D_801EE200);
}
