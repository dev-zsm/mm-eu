// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern void SubS_OfferTalkExchangeCustom(void *, void *, f32, f32, s32, s16 *, void *);
extern u8 SubS_ArePlayerAndActorFacing[];

void SubS_OfferTalkExchangeFacing(void *arg0, void *arg1, f32 arg2, f32 arg3, s32 arg4, s16 arg5, s16 arg6) {
    s32 pad;
    s16 sp28[2];

    sp28[0] = arg5;
    sp28[1] = arg6;
    SubS_OfferTalkExchangeCustom(arg0, arg1, arg2, arg3, arg4, sp28, SubS_ArePlayerAndActorFacing);
}
