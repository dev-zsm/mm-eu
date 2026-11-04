// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_SpawnWaterDroplets(struct PlayState* play, Vec3f* v) {
    static EffectSparkInit ref_D_801EE738;
    s32 effectIndex;

    ref_D_801EE738.position.x = v->x;
    ref_D_801EE738.position.y = v->y;
    ref_D_801EE738.position.z = v->z;
    ref_D_801EE738.uDiv = 5;
    ref_D_801EE738.vDiv = 5;
    ref_D_801EE738.colorStart[0].r = 255;
    ref_D_801EE738.colorStart[0].g = 255;
    ref_D_801EE738.colorStart[0].b = 255;
    ref_D_801EE738.colorStart[0].a = 255;
    ref_D_801EE738.colorStart[1].r = 100;
    ref_D_801EE738.colorStart[1].g = 100;
    ref_D_801EE738.colorStart[1].b = 100;
    ref_D_801EE738.colorStart[1].a = 100;
    ref_D_801EE738.colorStart[2].r = 100;
    ref_D_801EE738.colorStart[2].g = 100;
    ref_D_801EE738.colorStart[2].b = 100;
    ref_D_801EE738.colorStart[2].a = 100;
    ref_D_801EE738.colorStart[3].r = 100;
    ref_D_801EE738.colorStart[3].g = 100;
    ref_D_801EE738.colorStart[3].b = 100;
    ref_D_801EE738.colorStart[3].a = 100;
    ref_D_801EE738.colorEnd[0].r = 50;
    ref_D_801EE738.colorEnd[0].g = 50;
    ref_D_801EE738.colorEnd[0].b = 50;
    ref_D_801EE738.colorEnd[0].a = 50;
    ref_D_801EE738.colorEnd[1].r = 50;
    ref_D_801EE738.colorEnd[1].g = 50;
    ref_D_801EE738.colorEnd[1].b = 50;
    ref_D_801EE738.colorEnd[1].a = 50;
    ref_D_801EE738.colorEnd[2].r = 50;
    ref_D_801EE738.colorEnd[2].g = 50;
    ref_D_801EE738.colorEnd[2].b = 50;
    ref_D_801EE738.colorEnd[2].a = 50;
    ref_D_801EE738.colorEnd[3].r = 0;
    ref_D_801EE738.colorEnd[3].g = 0;
    ref_D_801EE738.colorEnd[3].b = 0;
    ref_D_801EE738.colorEnd[3].a = 0;
    ref_D_801EE738.timer = 0;
    ref_D_801EE738.duration = 16;
    ref_D_801EE738.speed = 8.0f;
    ref_D_801EE738.gravity = -1.0f;

    Effect_Add(play, &effectIndex, EFFECT_SPARK, 0, 1, &ref_D_801EE738);
}
