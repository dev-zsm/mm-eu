#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0x24];
    /* 0x24 */ f32 x;
    /* 0x28 */ f32 y;
    /* 0x2C */ f32 z;
    /* 0x30 */ u8 pad30[0x34];
    /* 0x64 */ f32 unk64;
    /* 0x68 */ f32 unk68;
    /* 0x6C */ f32 unk6C;
    /* 0x70 */ u8 pad70[0x34];
    /* 0xA4 */ f32 unkA4;
    /* 0xA8 */ f32 unkA8;
    /* 0xAC */ f32 unkAC;
} UpdatePosActor;

extern f32 D_801AF81C;

void Actor_UpdatePos(UpdatePosActor *actor) {
    f32 scale = D_801AF81C;

    actor->x += actor->unk64 * scale + actor->unkA4;
    actor->y += actor->unk68 * scale + actor->unkA8;
    actor->z += actor->unk6C * scale + actor->unkAC;
}
