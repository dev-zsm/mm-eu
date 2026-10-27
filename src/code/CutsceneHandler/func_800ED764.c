#include "types.h"

extern s32 Cutscene_StepTimer(void *arg0, u8 *arg1, f32 arg2);
extern void Audio_SetCutsceneFlag(s32 flag);

void CutsceneHandler_StopManual(void *arg0, u8 *arg1) {
    if (Cutscene_StepTimer(arg0, arg1, 0)) {
        Audio_SetCutsceneFlag(0);
        arg1[8] = 0;
    }
}
