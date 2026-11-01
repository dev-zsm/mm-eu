// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef s32 (*TalkExchangeFunc8013EAF8)(void *play, void *actor, void *data);

s32 Actor_OfferTalkExchange(void *, void *, s32, s32, s32);

s32 SubS_OfferTalkExchangeCustom(void *actor, void *play, s32 a2, s32 a3, s32 a4, void *data,
                                 TalkExchangeFunc8013EAF8 func) {
    s32 ret = 0;

    if ((func == NULL) || ((func != NULL) && func(play, actor, data))) {
        ret = Actor_OfferTalkExchange(actor, play, a2, a3, a4);
    }
    return ret;
}
