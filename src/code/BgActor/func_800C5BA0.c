#include "types.h"

typedef struct { f32 x, y, z; } Vec3f;
typedef struct { s16 x, y, z; } Vec3s;

typedef struct {
    u8 pad0[0x24];
    Vec3f scale;
    u8 pad30[0x28];
    Vec3f pos;
    u8 pad64[0x58];
    Vec3s rot;
} BgActorSrc;

typedef struct {
    BgActorSrc *actor;
    s32 id;
    u8 pad8[0xC];
    Vec3f curPos;
    Vec3s curRot;
    Vec3f curScale;
    Vec3f prevPos;
    Vec3s prevRot;
    Vec3f prevScale;
} BgActor;

void BgActor_SetActor(BgActor *bgActor, BgActorSrc *actor, s32 id) {
    bgActor->actor = actor;
    bgActor->id = id;
    bgActor->curPos = actor->pos;
    bgActor->curRot = actor->rot;
    bgActor->curRot.x--;
    bgActor->curScale = actor->scale;
    bgActor->prevPos = actor->pos;
    bgActor->prevRot = actor->rot;
    bgActor->prevScale = actor->scale;
}
