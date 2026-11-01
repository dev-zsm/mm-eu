#include "types.h"

typedef struct { f32 x, y, z; } Vec3f;
typedef struct {
    u8 pad0[0x24];
    Vec3f pos;
    u8 pad30[0x90 - 0x30];
    u16 bgCheckFlags;
} Actor;

void Math_Vec3f_Copy(Vec3f *dst, Vec3f *src);
f32 Math_SinS(s16 a);
f32 Math_CosS(s16 a);
void Actor_UpdateBgCheckInfo(s32 play, Actor *actor, f32 a, f32 b, f32 c, s32 flags);

s32 Actor_TestFloorInDirection(Actor *actor, s32 play, f32 distance, s16 angle) {
    struct { Vec3f saved; f32 dx; u16 savedFlags; } l;
    f32 cs;
    s16 ret;

    Math_Vec3f_Copy(&l.saved, &actor->pos);
    l.savedFlags = actor->bgCheckFlags;
    l.dx = Math_SinS(angle) * distance;
    cs = Math_CosS(angle);
    actor->pos.x += l.dx;
    actor->pos.z += cs * distance;
    Actor_UpdateBgCheckInfo(play, actor, 0.0f, 0.0f, 0.0f, 4);
    Math_Vec3f_Copy(&actor->pos, &l.saved);
    ret = actor->bgCheckFlags & 1;
    actor->bgCheckFlags = l.savedFlags;
    return ret;
}
