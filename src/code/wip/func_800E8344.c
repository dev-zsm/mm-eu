#include "types.h"

typedef struct { f32 x, y, z; } Vec3f;
typedef struct { u8 pad0[2]; s16 x, y, z; } Init;

extern Init D_801BAFF8;
extern s16 D_801BB026[3];
extern void Effect_Add(void *, s32 *, s32, s32, s32, void *);

void CollisionCheck_SpawnShieldParticles(void *play, Vec3f *pos) {
    s32 index;
    s32 x, y, z;

    x = pos->x;
    D_801BAFF8.x = x;
    y = pos->y;
    D_801BAFF8.y = y;
    z = pos->z;
    D_801BAFF8.z = z;
    D_801BB026[0] = x;
    D_801BB026[1] = y;
    D_801BB026[2] = z;
    Effect_Add(play, &index, 3, 0, 1, &D_801BAFF8);
}
