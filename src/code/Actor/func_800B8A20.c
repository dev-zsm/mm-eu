#include "types.h"

typedef struct {
    /* 0x000 */ u8 pad0[0x38C];
    /* 0x38C */ u8 unk38C;
    /* 0x38D */ u8 pad38D[3];
    /* 0x390 */ void *rideActor;
    /* 0x394 */ u8 pad394[0x6D8];
    /* 0xA6C */ u32 stateFlags;
} Player;

typedef struct {
    /* 0x0000 */ u8 pad0[0x1CCC];
    /* 0x1CCC */ Player *player;
} PlayState;

extern void CutsceneManager_Queue(s32 csId);

s32 Actor_SetRideActor(PlayState *play, void *rideActor, s32 mountSide) {
    Player *player = play->player;

    if (!(player->stateFlags & 0x3C7880)) {
        player->rideActor = rideActor;
        player->unk38C = mountSide;
        CutsceneManager_Queue(0x7C);
        return 1;
    }
    return 0;
}
