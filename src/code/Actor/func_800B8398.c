#include "types.h"
extern void Actor_OfferTalkExchangeEquiCylinder(void *a0, s32 a1, f32 a2, s32 a3);
void Actor_OfferTalk(void *a0, s32 a1, f32 a2) {
    Actor_OfferTalkExchangeEquiCylinder(a0, a1, a2, 0);
}
