#include "types.h"

typedef struct {
    u8 pad0[0xA4];
    s16 sceneId;
} PlayState;

extern s32 D_801C00F4[3];

extern s32 func_8016AE44(s16 sceneId);

s32 Map_GetMapIndexForOverworld(PlayState *play) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (func_8016AE44(play->sceneId) == D_801C00F4[i]) {
            return i;
        }
    }
    return -1;
}
