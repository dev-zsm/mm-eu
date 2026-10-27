// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    u8 pad0[0x24];
    Vec3f worldPos; /* 0x24 */
    u8 pad30[0x58 - 0x30];
    Vec3f scale; /* 0x58 */
    u8 pad64[0xBE - 0x64];
    s16 shapeRotY; /* 0xBE */
} Actor;

void SkelAnime_UpdateTranslation(void *skelAnime, Vec3f *diff, s16 angle);

void Actor_UpdatePosFromSkelAnime(Actor *actor, void *skelAnime) {
    Vec3f diff;

    SkelAnime_UpdateTranslation(skelAnime, &diff, actor->shapeRotY);
    actor->worldPos.x += diff.x * actor->scale.x;
    actor->worldPos.y += diff.y * actor->scale.y;
    actor->worldPos.z += diff.z * actor->scale.z;
}
