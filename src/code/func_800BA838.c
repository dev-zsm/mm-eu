// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Actor {
    u8 pad0[2];
    u8 category;
    u8 pad3[0x128 - 3];
    struct Actor *prev;
    struct Actor *next;
} Actor;

void Actor_AddToCategory(u8 *ctx, Actor *actor, u8 category) {
    s32 *entry;
    Actor *head;
    Actor *cur;

    actor->category = category;
    ctx[0xE]++;
    entry = (s32 *)((u32)ctx + category * 12);
    entry[4]++;
    head = (Actor *)entry[5];
    if (head == NULL) {
        entry[5] = (s32)actor;
        return;
    }
    cur = head->next;
    if (cur != NULL) {
        do {
            head = cur;
            cur = cur->next;
        } while (cur != NULL);
    }
    head->next = actor;
    actor->prev = head;
}
