#include "types.h"

typedef struct {
    u8 pad0[0x92];
    s16 unk92;
    u8 pad94[0x2A];
    s16 unkBE;
} Actor_800B7164;

s32 Actor_IsFacingPlayer(Actor_800B7164 *actor, s16 range) {
    s16 diff = actor->unk92 - actor->unkBE;
    s32 absDiff;

    if (diff < 0) {
        absDiff = -diff;
    } else {
        absDiff = diff;
    }
    if (absDiff < range) {
        return 1;
    }
    return 0;
}
