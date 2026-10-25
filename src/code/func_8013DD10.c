#include "types.h"

typedef struct Actor {
    s16 id;
    u8 pad2[0x12A];
    struct Actor *next;
} Actor;

typedef struct {
    s32 unk0;
    Actor *head;
    s32 unk8;
} ActorList;

typedef struct {
    u8 pad0[0x1CB0];
    ActorList lists[12];
} PlayState;

Actor *SubS_FindActor(PlayState *play, Actor *actor, u8 category, s16 id) {
    Actor *cur = actor;

    if (actor == NULL) {
        cur = play->lists[category].head;
    }
    if (cur != NULL && id != cur->id) {
        do {
            cur = cur->next;
        } while (cur != NULL && id != cur->id);
    }
    return cur;
}
