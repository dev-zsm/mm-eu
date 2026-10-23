// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern void Actor_OfferOcarinaInteraction(s32, s32, f32, f32);
void Actor_OfferOcarinaInteractionNearby(s32 a0, s32 a1, f32 a2) {
    Actor_OfferOcarinaInteraction(a0, a1, a2, 20.0f);
}
