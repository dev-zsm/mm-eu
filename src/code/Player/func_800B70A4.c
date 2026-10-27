#include "types.h"

typedef struct {
    u8 pad[0xBE];
    s16 yaw;
} PlayerLike;
typedef struct {
    u8 pad[0x1CCC];
    PlayerLike *player;
} PlayStateLike;
typedef struct {
    u8 pad[0x92];
    s16 yaw;
} ActorLike;
s32 Player_IsFacingActor(ActorLike *actor, s16 maxDiff, PlayStateLike *play) {
    PlayerLike *player = play->player;
    s16 diff = ((short) (actor->yaw + 0x8000)) - player->yaw;
    s32 absDiff;
    if (diff < 0) {
        absDiff = -diff;
    } else {
        absDiff = diff;
    }
    if (absDiff < maxDiff) {
        return 1;
    }
    return 0;
}
