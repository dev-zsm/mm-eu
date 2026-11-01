#include "types.h"

extern f32 D_801D4B18;

void Actor_OfferGetItem(void *, void *, void *, f32, f32);

void Actor_OfferGetItemFar(void *arg0, void *arg1, void *arg2) {
    Actor_OfferGetItem(arg0, arg1, arg2, D_801D4B18, D_801D4B18);
}
