#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0xA4];
    /* 0xA4 */ s16 sceneId;
} MapContext;

extern s32 func_8016AE44(s16 sceneId);
extern s32 D_801C00E4[4];

s32 Map_GetDungeonSceneIndexForBoss(MapContext *ctx) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (func_8016AE44(ctx->sceneId) == D_801C00E4[i]) {
            return i;
        }
    }
    return -1;
}
