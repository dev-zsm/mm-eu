// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad[0xB0];
    s16 unkB0;
} Actor;

void Actor_OfferOcarinaInteractionNearby(void *, s32, f32);

void Actor_OfferOcarinaInteractionColChkInfoCylinder(Actor *arg0, s32 arg1) {
    f32 sp;

    sp = (f32)arg0->unkB0 + 50.0f;
    Actor_OfferOcarinaInteractionNearby(arg0, arg1, sp);
}
