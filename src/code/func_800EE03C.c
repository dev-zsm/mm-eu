#include "types.h"

typedef struct {
    u8 pad0[0x1F2C];
    u8 hasCues;
    u8 pad1[0x1F4C - 0x1F2D];
    s32 cueChannels[1];
} CutsceneContext;

extern s32 Cutscene_GetCueChannel(CutsceneContext *csCtx, u16 cueId);

s32 Cutscene_IsCueInChannel(CutsceneContext *csCtx, u16 cueId) {
    s32 channel;

    if (csCtx->hasCues) {
        channel = Cutscene_GetCueChannel(csCtx, cueId);
        if (channel != -1) {
            return csCtx->cueChannels[channel] != 0;
        }
    }
    return 0;
}
