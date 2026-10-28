#include "types.h"
typedef struct { u8 pad0[0x116]; s16 unk116; } B;
typedef s16 (*Fn)(void *, void *);
extern s32 Actor_TalkOfferAccepted(void *, void *);
extern s32 Actor_OnScreen(void *, void *);
extern s32 Actor_OfferTalk(void *, void *, s32);
s32 Npc_UpdateTalking(void *a, B *b, s16 *state, s32 c, Fn f1, Fn f2) {
    if (Actor_TalkOfferAccepted(b, a) != 0) {
        *state = 1;
        return 1;
    }
    if (*state != 0) {
        *state = f2(a, b);
        return 0;
    }
    if (Actor_OnScreen(a, b) == 0) {
        return 0;
    }
    if (Actor_OfferTalk(b, a, c) == 0) {
        return 0;
    }
    b->unk116 = f1(a, b);
    return 0;
}
