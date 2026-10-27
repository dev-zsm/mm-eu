#include "types.h"

typedef struct {
    u8 pad0[0xA6C];
    u32 stateFlags1;
    u8 padA70[4];
    u32 stateFlags2;
} Player;

typedef struct {
    u8 pad0[0x1CCC];
    Player *player;
} PlayState;

typedef struct {
    u8 pad0[0x8C];
    PlayState *play;
    Player *target;
} Camera;

s32 Camera_IsChargingSpinAttackOrDekuFlowerDive(Camera *camera) {
    Player *player = camera->target;

    if (player == camera->play->player) {
        s32 charging = (player->stateFlags1 & 0x1000) != 0;

        if (!charging) {
            charging = (player->stateFlags2 & 0x100) != 0;
        }
        return charging;
    }
    return 0;
}
