// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x24];
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    s16 unk30;
    s16 unk32;
    s16 unk34;
    u8 pad36[0x3C - 0x36];
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    s16 unk48;
    s16 unk4A;
    s16 unk4C;
} Actor;

void Actor_SetFocus(Actor *actor, f32 arg1) {
    actor->unk3C = actor->unk24;
    actor->unk40 = actor->unk28 + arg1;
    actor->unk44 = actor->unk2C;
    actor->unk48 = actor->unk30;
    actor->unk4A = actor->unk32;
    actor->unk4C = actor->unk34;
}
