#include "types.h"
typedef struct { u8 pad0[0x98]; f32 yDist; f32 xzDist; } Actor;
typedef struct { u8 pad0[4]; u32 flags; u8 pad8[0xA94 - 8]; } PlayerBase;
typedef struct { u8 pad0[0x1CCC]; void *player; } Play;
typedef struct { u32 pad0; u32 flags; u8 pad8[0xA88 - 8]; u8 padA88[8]; Actor *target; f32 targetY; } Player;
extern s32 Player_InCsMode(void *);
float fabsf(float);
#pragma intrinsic (fabsf)

s32 Actor_OfferOcarinaInteraction(Actor *actor, Play *play, f32 yRange, f32 xzRange) {
    Player *player = (Player *)play->player;

    if ((player->flags & 0x20000000) || Player_InCsMode(play) || xzRange < fabsf(actor->xzDist) ||
        player->targetY < actor->yDist || yRange < actor->yDist) {
        return 0;
    }
    player->target = actor;
    player->targetY = actor->yDist;
    return 1;
}
