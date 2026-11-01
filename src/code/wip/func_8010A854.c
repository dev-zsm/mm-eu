#include "types.h"

typedef struct { u8 pad0[4]; u32 flags; u8 pad8[0x90]; f32 unk98; f32 unk9C; } Act;
f32 fabsf(f32);
#pragma intrinsic (fabsf)
s32 Actor_TalkOfferAccepted(Act *a, s32 play);
void Actor_OfferTalkExchange(Act *a, s32 play, f32 b, f32 c, s32 d);

s32 MsgEvent_Autotalk(Act *actor, s32 play, u8 **script, s32 unused) {
    s32 pad;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    s16 sp26;
    u8 *cmd = *script;

    sp30 = actor->unk98 + 1.0f;
    sp2C = fabsf(actor->unk9C) + 1.0f;
    sp26 = (cmd[1] << 8) | cmd[2];
    if (Actor_TalkOfferAccepted(actor, play) != 0) {
        *script += sp26;
        return 0;
    }
    actor->flags |= 0x10000;
    sp28 = actor->unk98;
    actor->unk98 = 0.0f;
    Actor_OfferTalkExchange(actor, play, sp30, sp2C, 0);
    actor->unk98 = sp28;
    return 1;
}
