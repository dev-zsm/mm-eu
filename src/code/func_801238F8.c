#include "types.h"

typedef struct {
    u8 pad0[0x14B];
    u8 id;
    u8 pad14C[0x730 - 0x14C];
    s32 unk730;
    u8 pad734[0xA6C - 0x734];
    u32 stateFlags;
} Player;

typedef struct {
    u8 pad0[0x1CCC];
    Player *player;
} PlayState;

extern s32 Player_FriendlyLockOnOrParallel(Player *player);

s32 func_801238F8(PlayState *play) {
    Player *player = play->player;

    return (player->stateFlags & 0x400000) &&
           (player->id != 4 || (!Player_FriendlyLockOnOrParallel(player) && !player->unk730));
}
