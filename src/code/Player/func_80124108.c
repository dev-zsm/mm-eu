// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x147];
    s8 unk147;
    u8 pad148[2];
    s8 unk14A;
    u8 pad14B[0xAA5 - 0x14B];
    u8 unkAA5;
} Player;

s32 Player_ActionToModelGroup(Player *, s32);
void Player_SetModelGroup(Player *, s32);

void func_80124108(Player *player) {
    player->unk14A = player->unk147;
    Player_SetModelGroup(player, Player_ActionToModelGroup(player, player->unk147));
    player->unkAA5 = 0;
}
