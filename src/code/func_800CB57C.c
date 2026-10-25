#include "types.h"

typedef struct {
    u8 pad0[0xA74];
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
u32 func_800CB57C(Camera *camera) {
    Camera *new_var;
    Player *new_var2;
    if (camera->target) {
    }
    new_var = camera;
    new_var2 = new_var->target;
    if (new_var2 == new_var->play->player) {
        return new_var2->stateFlags2 & 0x10;
    }
    return 0;
}
