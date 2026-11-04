// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_GreenBlood(struct PlayState* play, Collider* col, Vec3f* v) {
    static EffectSparkInit ref_D_801EF0C8;
    s32 effectIndex;

    ref_D_801EF0C8.position.x = v->x;
    ref_D_801EF0C8.position.y = v->y;
    ref_D_801EF0C8.position.z = v->z;
    ref_D_801EF0C8.uDiv = 5;
    ref_D_801EF0C8.vDiv = 5;
    ref_D_801EF0C8.colorStart[0].r = 10;
    ref_D_801EF0C8.colorStart[0].g = 200;
    ref_D_801EF0C8.colorStart[0].b = 10;
    ref_D_801EF0C8.colorStart[0].a = 255;
    ref_D_801EF0C8.colorStart[1].r = 0;
    ref_D_801EF0C8.colorStart[1].g = 128;
    ref_D_801EF0C8.colorStart[1].b = 0;
    ref_D_801EF0C8.colorStart[1].a = 255;
    ref_D_801EF0C8.colorStart[2].r = 0;
    ref_D_801EF0C8.colorStart[2].g = 128;
    ref_D_801EF0C8.colorStart[2].b = 0;
    ref_D_801EF0C8.colorStart[2].a = 255;
    ref_D_801EF0C8.colorStart[3].r = 0;
    ref_D_801EF0C8.colorStart[3].g = 128;
    ref_D_801EF0C8.colorStart[3].b = 0;
    ref_D_801EF0C8.colorStart[3].a = 255;
    ref_D_801EF0C8.colorEnd[0].r = 0;
    ref_D_801EF0C8.colorEnd[0].g = 32;
    ref_D_801EF0C8.colorEnd[0].b = 0;
    ref_D_801EF0C8.colorEnd[0].a = 0;
    ref_D_801EF0C8.colorEnd[1].r = 0;
    ref_D_801EF0C8.colorEnd[1].g = 32;
    ref_D_801EF0C8.colorEnd[1].b = 0;
    ref_D_801EF0C8.colorEnd[1].a = 0;
    ref_D_801EF0C8.colorEnd[2].r = 0;
    ref_D_801EF0C8.colorEnd[2].g = 64;
    ref_D_801EF0C8.colorEnd[2].b = 0;
    ref_D_801EF0C8.colorEnd[2].a = 0;
    ref_D_801EF0C8.colorEnd[3].r = 0;
    ref_D_801EF0C8.colorEnd[3].g = 64;
    ref_D_801EF0C8.colorEnd[3].b = 0;
    ref_D_801EF0C8.colorEnd[3].a = 0;
    ref_D_801EF0C8.timer = 0;
    ref_D_801EF0C8.duration = 16;
    ref_D_801EF0C8.speed = 8.0f;
    ref_D_801EF0C8.gravity = -1.0f;
    Effect_Add(play, &effectIndex, EFFECT_SPARK, 0, 1, &ref_D_801EF0C8);
}
