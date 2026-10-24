#include "types.h"

typedef struct {
    u8 pad0[0xA70];
    u32 stateFlags1;
    u8 pad_A74[0x73];
    s8 mode;
} Player;

typedef struct {
    u8 pad0[0x1CCC];
    Player *player;
} PlayState;

s32 Player_IsSideJumping(PlayState *play) {
    Player *player = play->player;

    return (player->stateFlags1 & 0x80000) && (player->mode == 1 || player->mode == 3);
}
