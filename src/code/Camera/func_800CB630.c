#include "types.h"

typedef struct {
    u8 pad0[0xA6C];
    u32 unkA6C;
    u32 unkA70;
    u32 stateFlags;
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

s32 Camera_IsSwimming(Camera *camera) {
    Player *player = camera->player;

    if (player == camera->play->player) {
        if (player->stateFlags & 0x8000) {
            return 999;
        }
        return player->unkA6C & 0x8000000;
    }
    return 0;
}
