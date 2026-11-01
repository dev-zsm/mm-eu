#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ u32 flags;
    /* 0x08 */ u8 pad8[0x90];
    /* 0x98 */ f32 xzDistToPlayer;
    /* 0x9C */ f32 yDistToPlayer;
    /* 0xA0 */ u8 padA0[0x74];
    /* 0x114 */ u8 unk114;
} SubsActor;

float fabsf(float);
#pragma intrinsic (fabsf)

void Actor_GetScreenPos(void* play, SubsActor* actor, s16* x, s16* y);
s32 Actor_OfferGetItem(SubsActor* actor, void* play, s32 getItemId, f32 xzRange, f32 yRange);
s32 Actor_OfferTalkExchange(SubsActor* actor, void* play, f32 xzRange, f32 yRange, s32 exchangeItemId);

s32 SubS_Offer(SubsActor* actor, void* play, f32 xzRange, f32 yRange, s32 itemId, s32 mode) {
    s32 ret = 0;
    s16 x;
    s16 y;

    Actor_GetScreenPos(play, actor, &x, &y);
    switch (mode) {
        case 1:
            ret = Actor_OfferGetItem(actor, play, itemId, actor->xzDistToPlayer + 1.0f,
                                     fabsf(actor->yDistToPlayer) + 1.0f);
            break;
        case 2:
            if ((fabsf(actor->yDistToPlayer) <= yRange) && (actor->xzDistToPlayer <= xzRange)) {
                ret = Actor_OfferTalkExchange(actor, play, xzRange, yRange, itemId);
            }
            break;
        case 3:
            if ((x >= 0) || (x < 320)) {
                if ((y >= 0) || (y < 240)) {
                    ret = Actor_OfferTalkExchange(actor, play, xzRange, yRange, itemId);
                }
            }
            break;
        case 4: {
            f32 savedDist = actor->xzDistToPlayer;

            actor->flags |= 0x10000;
            actor->xzDistToPlayer = 0.0f;
            ret = Actor_OfferTalkExchange(actor, play, savedDist + 1.0f, fabsf(actor->yDistToPlayer) + 1.0f, itemId);
            actor->xzDistToPlayer = savedDist;
            break;
        }
        case 5:
            if ((x >= 0) || (x < 320)) {
                if ((y >= 0) || (y < 240)) {
                    if (fabsf(actor->yDistToPlayer) <= yRange) {
                        if (actor->xzDistToPlayer <= xzRange) {
                            if (actor->unk114 != 0) {
                                actor->flags |= 0x10000;
                                ret = Actor_OfferTalkExchange(actor, play, xzRange, yRange, itemId);
                            }
                        }
                    }
                }
            }
            break;
        case 6:
            if ((x >= 0) || (x < 320)) {
                if ((y >= 0) || (y < 240)) {
                    if (fabsf(actor->yDistToPlayer) <= yRange) {
                        if (actor->xzDistToPlayer <= xzRange) {
                            actor->flags |= 0x10000;
                            ret = Actor_OfferTalkExchange(actor, play, xzRange, yRange, itemId);
                        }
                    }
                }
            }
            break;
    }
    return ret;
}
