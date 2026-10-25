#include "types.h"

typedef struct Actor {
    u8 pad0[0x1C];
    s16 params;
    u8 pad1E[0x12C - 0x1E];
    struct Actor *next;
    u8 pad130[0x160 - 0x130];
    s32 pathIndex;
} Actor;

extern Actor *SubS_FindActor(void *play, Actor *actorListStart, s32 actorCategory, s32 actorId);

s32 Horse_GetJumpingFencePathIndex(void *play) {
    Actor *actor = NULL;

    while (1) {
        actor = SubS_FindActor(play, actor, 6, 0x7C);
        if (actor != NULL) {
            if (actor->params == 2) {
                return actor->pathIndex;
            }
            actor = actor->next;
        } else {
            break;
        }
    }
    return -1;
}
