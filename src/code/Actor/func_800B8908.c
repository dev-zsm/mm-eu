// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern void Actor_OfferGetItem(s32, s32, s32, f32, f32);
void Actor_OfferGetItemNearby(s32 a0, s32 a1, s32 a2) {
    Actor_OfferGetItem(a0, a1, a2, 50.0f, 10.0f);
}
