// FLAGS: -O2 -g3 -mips2
#include "types.h"

struct Actor;
typedef struct {
    s32 length;
    struct Actor *first;
    s32 unk8;
} ActorList;

typedef struct {
    u8 pad0[0xE];
    u8 total;
    u8 padF;
    ActorList lists[12];
} ActorCtx;

typedef struct Actor {
    u8 pad0[2];
    u8 category;
    s8 room;
    u8 pad4[0x124];
    struct Actor *prev;
    struct Actor *next;
} Actor;

typedef struct {
    u8 pad0[0x186E0];
    s8 room;
} Play;

extern void Flags_SetClearTemp(Play *a, s32 b);

Actor *Actor_RemoveFromCategory(Play *play, ActorCtx *actorCtx, Actor *actor) {
    Actor *newHead;
    s8 room;

    actorCtx->total--;
    actorCtx->lists[actor->category].length--;
    if (actor->prev != NULL) {
        actor->prev->next = actor->next;
    } else {
        actorCtx->lists[actor->category].first = actor->next;
    }
    newHead = actor->next;
    if (newHead != NULL) {
        newHead->prev = actor->prev;
    }
    actor->next = NULL;
    actor->prev = NULL;
    room = play->room;
    if (room == actor->room && actor->category == 5 && *(s32 *)((u8 *)actorCtx + 0x4C) == 0) {
        Flags_SetClearTemp(play, room);
    }
    return newHead;
}
