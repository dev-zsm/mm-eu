#include "types.h"

typedef struct {
    u8 pad0[0x14B];
    u8 unk14B;
} Player;
typedef struct {
    u8 pad0[0x1CCC];
    Player *player;
} PlayState;
typedef struct {
    u8 pad0[0x8C];
    PlayState *play;
    Player *player;
} Camera;
s32 Camera_IsPlayerFormZora(Camera *arg0) {
    PlayState *play = arg0->play;
    Player *player = arg0->player;
    if (!arg0->player) {
        } if (player == arg0->play->player) {
        return player->unk14B == 2;
    }
    return 0;
}
