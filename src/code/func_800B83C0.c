// FLAGS: -O2 -g3 -mips2
#include "types.h"

void Actor_OfferTalk(void *, s32, f32);

void Actor_OfferTalkNearColChkInfoCylinder(void *arg0, s32 arg1) {
    f32 temp;

    temp = (f32)*(s16 *)((u8 *)arg0 + 0xB0) + 50.0f;
    Actor_OfferTalk(arg0, arg1, temp);
}
