#include "types.h"

typedef struct {
    u8 pad0[8];
    u8 state;
    u8 pad9[0x24 - 9];
    void *unk24;
    void *unk28[10];
} CutsceneContext;

typedef struct {
    u8 pad0[8];
    s32 unk8;
    u8 padC[0x3CA8 - 0xC];
    s32 unk3CA8;
} SaveContext;

extern SaveContext D_801E6EF0;
s32 Cutscene_StepTimer(void *play, CutsceneContext *csCtx, f32 arg2);
void func_800F1D6C(s32 arg0);
void Audio_SetCutsceneFlag(s32 arg0);

void CutsceneHandler_StopScript(void *play, CutsceneContext *csCtx) {
    s16 i;

    if (Cutscene_StepTimer(play, csCtx, 0.0f)) {
        csCtx->unk24 = NULL;
        for (i = 0; i < 10; i++) {
            csCtx->unk28[i] = NULL;
        }
        D_801E6EF0.unk8 = 0;
        D_801E6EF0.unk3CA8 = 0;
        func_800F1D6C(0x7F);
        Audio_SetCutsceneFlag(0);
        csCtx->state = 0;
    }
}
