#include "types.h"

typedef struct {
    /* 0x00000 */ u8 pad0[0x9C];
    /* 0x0009C */ u32 frames;
    /* 0x000A0 */ u8 padA0[0x17056];
    /* 0x170F6 */ u8 unk170F6;
    /* 0x170F7 */ u8 unk170F7;
    /* 0x170F8 */ u8 pad170F8[2];
    /* 0x170FA */ u8 unk170FA;
} RainState;

void Environment_UpdateRain(RainState *play) {
    u8 rainA = play->unk170FA;
    u8 rainB = play->unk170F6;
    u8 target = rainA;
    u8 current;

    if (rainA < rainB) {
        target = rainB;
    }
    current = play->unk170F7;
    if (target != current && (play->frames & 7) == 0) {
        if (current < target) {
            play->unk170F7 = current + 2;
        } else {
            play->unk170F7 = current - 2;
        }
    }
}
