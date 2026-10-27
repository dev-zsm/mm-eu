#include "types.h"
typedef struct Actor { s16 id; u8 pad2[0x12A]; struct Actor *next; } Actor;
typedef struct { s32 length; Actor *head; s32 pad; } ActorList;
typedef struct { u8 pad0[0x1CB0]; ActorList lists[12]; } Play;
extern f32 Actor_WorldDistXYZToActor(Actor *, Actor *);

Actor *Actor_FindNearby(Play *play, Actor *refActor, s16 actorId, u8 category, f32 range) {
    Actor *actor = play->lists[category].head;

    while (actor != NULL) {
        if (actor == refActor || (actorId != -1 && actorId != actor->id)) {
            actor = actor->next;
        } else if (Actor_WorldDistXYZToActor(refActor, actor) <= range) {
            return actor;
        } else {
            actor = actor->next;
        }
    }
    return NULL;
}
