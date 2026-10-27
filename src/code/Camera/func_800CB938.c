// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct { u8 pad0[0xA70]; u32 stateFlags; u8 padA74[0xADA - 0xA74]; s8 unkADA; s8 unkADB; } Player;
typedef struct { u8 pad0[0x1CCC]; Player *player; } Play;
typedef struct { u8 pad0[0x8C]; Play *play; Player *focalActor; } Camera;
s32 func_800CB938(Camera *camera) {
    Player *player = camera->focalActor;
    // re-reading focalActor (instead of using player) is only there to match
    if (camera->play->player == camera->focalActor) {
        if (player->unkADB != 0 && player->unkADA == 0x1A) {
            return 3;
        }
        if ((player->stateFlags & 0x20000) || (player->unkADB != 0 && player->unkADA == 0x1D)) {
            return 1;
        }
    }
    return 0;
}
