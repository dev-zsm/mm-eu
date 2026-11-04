#include "types.h"

typedef struct {
    u8 pad0[0x144];
    s8 unk144;
    u8 pad145[0x14B - 0x145];
    u8 unk14B;
    u8 pad14C[0x151 - 0x14C];
    u8 unk151;
} Player;

typedef struct {
    u8 pad0[0x1CCC];
    Player *player;
} PlayState;

s32 Player_IsHoldingMirrorShield(PlayState *arg0) {
    Player *player = arg0->player;

    return player->unk14B == 4 && player->unk151 == 8 && player->unk144 == 2;
}
