#include "types.h"

typedef struct { u8 pad0[0x98]; f32 unk98; f32 unk9C; u8 padA0[0x74]; u8 unk114; } Act;
typedef struct { u8 pad0[4]; u32 unk4; u8 pad8[0xA7F]; s8 unkA87; Act *unkA88; f32 unkA8C; } Plyr;
typedef struct { u8 pad0[0x1CCC]; Plyr *player; } PlayCtx;
f32 fabsf(f32);
#pragma intrinsic (fabsf)
s32 Player_InCsMode(PlayCtx *play);
void CutsceneManager_Queue(s32 a);

s32 Actor_OfferTalkExchange(Act *actor, PlayCtx *play, f32 xzRange, f32 yRange, s32 exchangeItemId) {
    Plyr *player = play->player;

    if ((player->unk4 & 0x100) ||
        ((exchangeItemId > 0) && Player_InCsMode(play)) ||
        ((actor->unk114 == 0) &&
         ((fabsf(actor->unk9C) > fabsf(yRange)) || (player->unkA8C < actor->unk98) || (xzRange < actor->unk98)))) {
        return 0;
    }
    player->unkA88 = actor;
    player->unkA8C = actor->unk98;
    player->unkA87 = exchangeItemId;
    CutsceneManager_Queue(0x7C);
    return 1;
}
