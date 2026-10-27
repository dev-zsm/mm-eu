#include "types.h"

typedef struct Actor {
    /* 0x00 */ u8 pad0[0x1E];
    /* 0x1E */ s8 objBankIndex;
    /* 0x1F */ u8 pad1F[0x12C - 0x1F];
    /* 0x12C */ struct Actor *next;
} Actor;

typedef struct {
    s32 unk0;
    Actor *first;
    s32 unk8;
} ActorList;

typedef struct {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ ActorList lists[12];
} ActorCtx;

extern s32 Object_IsLoaded(void *objCtx, s32 bank);
extern void Actor_Kill(Actor *a);

void Actor_KillAllWithMissingObject(u8 *play, ActorCtx *ctx) {
    s32 i;
    Actor *actor;
    void *objCtx = play + 0x17D88;

    for (i = 0; i < 12; i++) {
        actor = ctx->lists[i].first;
        while (actor != 0) {
            if (Object_IsLoaded(objCtx, actor->objBankIndex) == 0) {
                Actor_Kill(actor);
            }
            actor = actor->next;
        }
    }
}
