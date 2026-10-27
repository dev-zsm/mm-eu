#include "types.h"

typedef struct {
    u8 pad0[0x39];
    u8 unk39;
    u8 pad3A[0x16];
    u16 unk50;
} Actor;

void Actor_PlaySfx_Flagged2(Actor *actor, u16 sfxId) {
    actor->unk50 = sfxId;
    actor->unk39 &= ~0x1F;
    actor->unk39 |= 2;
}
