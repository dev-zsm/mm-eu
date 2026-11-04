#include "types.h"

typedef struct {
    char pad0[0x144];
    s8 unk144;
    char pad145[6];
    u8 unk14B;
} Player;

typedef struct {
    char pad0[0x1CCC];
    Player *player;
} PlayState;

s32 Player_HasMirrorShieldEquipped(PlayState *play) {
    Player *player = play->player;

    return (player->unk14B == 4) && (player->unk144 == 2);
}
