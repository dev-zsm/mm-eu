#include "types.h"

typedef struct {
    s8 unk0;
    s8 unk1;
    s8 unk2;
    u8 pad3[0xD];
} Struct_8016B1B4_Entry;

typedef struct {
    u8 pad0[2];
    u8 category;
    s8 unk3;
    u8 pad4[0x1C - 4];
    u16 params;
    u8 pad1E[0xBE - 0x1E];
    s16 shapeRotY;
} Actor;

s32 func_8016B1B4(u8 *play, Actor *actor, s16 *rotY) {
    Struct_8016B1B4_Entry *entry;
    s8 v;

    if (actor->category != 0xA) {
        return 0;
    }
    entry = &(*(Struct_8016B1B4_Entry **)(play + 0x18764))[actor->params >> 10];
    v = entry->unk0;
    if (v == entry->unk2) {
        return 0;
    }
    if (v == actor->unk3) {
        *rotY = actor->shapeRotY;
    } else {
        *rotY = actor->shapeRotY + 0x8000;
    }
    return 1;
}
