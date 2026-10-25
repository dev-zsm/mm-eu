#include "types.h"

typedef struct {
    /* 0x000 */ u8 pad0[0x3BA];
    /* 0x3BA */ s16 unk3BA;
} Player;

typedef struct {
    /* 0x0000 */ u8 pad0[0x1CCC];
    /* 0x1CCC */ Player *player;
} PlayState;

extern s32 Player_SetCsAction(PlayState *play, void *actor, u8 csAction);

s32 Player_SetCsActionWithHaltedActors(PlayState *play, void *actor, u8 csAction) {
    Player *player = play->player;

    if (Player_SetCsAction(play, actor, csAction) != 0) {
        player->unk3BA = 1;
        return 1;
    }
    return 0;
}
