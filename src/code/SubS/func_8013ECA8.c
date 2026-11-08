// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern void SubS_OfferTalkExchangeCustom(void *, void *, f32, f32, s32, s16 *, void *);
extern u8 SubS_ArePlayerAndActorFacing[];

s32 SubS_OfferTalkExchangeFacing(struct Actor *actor, struct PlayState *play, f32 xzRange, f32 yRange, s32 exchangeItemAction, s16 playerYawRange, s16 actorYawRange) {
    s32 pad;
    s16 sp28[2];

    sp28[0] = playerYawRange;
    sp28[1] = actorYawRange;
    SubS_OfferTalkExchangeCustom(actor, play, xzRange, yRange, exchangeItemAction, sp28, SubS_ArePlayerAndActorFacing);
}
