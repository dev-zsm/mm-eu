#include "types.h"
void Actor_OfferTalkExchange(s32, s32, f32, f32, s32);
void Actor_OfferTalkExchangeEquiCylinder(s32 a0, s32 a1, f32 a2, s32 a3) {
    Actor_OfferTalkExchange(a0, a1, a2, a2, a3);
}
