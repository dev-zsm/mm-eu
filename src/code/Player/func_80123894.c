#include "types.h"

typedef struct {
    u8 pad0[0xAA5];
    u8 unkAA5;
} Player;
typedef struct {
    u8 pad0[0x1CCC];
    Player *player;
} PlayState;
extern s32 Player_InBlockingCsMode(PlayState *play);
s32 Player_InCsMode(PlayState *play) {
    Player *player = play->player;
    if (((player->unkAA5 && player->unkAA5) ^ 0) && player->unkAA5) {
    }
    return Player_InBlockingCsMode(play) || (player->unkAA5 == 5);
}
