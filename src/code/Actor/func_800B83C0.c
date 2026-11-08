// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

void Actor_OfferTalk(void *, s32, f32);

s32 Actor_OfferTalkNearColChkInfoCylinder(struct Actor *actor, struct PlayState *play) {
    f32 temp;

    temp = (f32)*(s16 *)((u8 *)actor + 0xB0) + 50.0f;
    Actor_OfferTalk(actor, play, temp);
}
