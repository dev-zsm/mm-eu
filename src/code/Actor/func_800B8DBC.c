#include "types.h"

typedef struct {
    u8 pad0[0x39];
    u8 flags;
    u8 pad3A[0x16];
    s16 unk50;
} Actor;

void Actor_PlaySfx_FlaggedTimer(Actor *actor, s32 timer) {
    actor->flags &= ~0x1F;
    actor->flags |= 0x10;
    if (timer < 0x28) {
        actor->unk50 = 3;
    } else if (timer < 0x64) {
        actor->unk50 = 2;
    } else {
        actor->unk50 = 1;
    }
}
