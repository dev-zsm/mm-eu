#include "types.h"

typedef struct {
    s16 sceneId;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} SceneLimits;

typedef struct {
    u8 pad0[0xA4];
    s16 sceneId;
} Ctx;

extern SceneLimits D_801B5230[1];

s32 BgCheck_GetSpecialSceneMaxObjects(Ctx *ctx, s32 *out0, s32 *out1, s32 *out2) {
    s32 i;

    for (i = 0; i < 1; i++) {
        if (ctx->sceneId == D_801B5230[i].sceneId) {
            *out0 = D_801B5230[i].unk2;
            *out1 = D_801B5230[i].unk4;
            *out2 = D_801B5230[i].unk6;
            return 1;
        }
    }
    return 0;
}
