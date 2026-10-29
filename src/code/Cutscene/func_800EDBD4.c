#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ u16 unk2;
    /* 0x04 */ u16 unk4;
    /* 0x06 */ u8 pad6[6];
    /* 0x0C */ s32 startX;
    /* 0x10 */ s32 startY;
    /* 0x14 */ s32 startZ;
    /* 0x18 */ s32 endX;
    /* 0x1C */ s32 endY;
    /* 0x20 */ s32 endZ;
} CsEntry;

typedef struct {
    /* 0x0000 */ u8 pad0[0x1F34];
    /* 0x1F34 */ u16 frames;
    /* 0x1F36 */ u8 pad1F36[0x16];
    /* 0x1F4C */ CsEntry *entries[1];
} Play;

typedef struct {
    /* 0x00 */ u8 pad0[0x24];
    /* 0x24 */ f32 x;
    /* 0x28 */ f32 y;
    /* 0x2C */ f32 z;
} Act;

extern f32 Environment_LerpWeight();

void Cutscene_ActorTranslate(Act *actor, Play *play, s32 idx) {
    f32 startZ, startY, startX, endZ, endY, endX, t;
    CsEntry *e = play->entries[idx];

    startX = e->startX;
    startY = e->startY;
    startZ = e->startZ;
    endX = e->endX;
    endY = e->endY;
    endZ = e->endZ;
    t = Environment_LerpWeight(e->unk4, e->unk2, play->frames, play);

    actor->x = (endX - startX) * t + startX;
    actor->y = (endY - startY) * t + startY;
    actor->z = (endZ - startZ) * t + startZ;
}
