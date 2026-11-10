#include "types.h"

typedef struct {
    /* 0x000 */ u8 pad0[0x14B];
    /* 0x14B */ u8 mode;
    /* 0x14C */ u8 pad14C[0xA6C - 0x14C];
    /* 0xA6C */ u32 flagsA6C;
    /* 0xA70 */ u32 padA70;
    /* 0xA74 */ u32 flagsA74;
} Actor;

f32 func_800B6D4C(Actor *actor) {
    f32 base;

    if (actor->flagsA6C & 0x00800000) {
        base = 32.0f;
    } else {
        base = 0.0f;
    }

    switch (actor->mode) {
        case 0:
        default:
            return base + 124.0f;
        case 1:
            return ((actor->flagsA74 & 0x1000) ? 34.0f : 80.0f) + base;
        case 2:
            return base + 68.0f;
        case 3:
            return base + 36.0f;
        case 4:
            return base + 44.0f;
    }
}
