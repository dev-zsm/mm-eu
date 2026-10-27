#include "types.h"

extern u8 D_801C6A80[];
extern f32 D_801D4B20;

extern void TransitionCircle_LoadAndSetTexture(void *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 arg6);

void Actor_DrawLensOverlay(void *arg0, s32 arg1) {
    TransitionCircle_LoadAndSetTexture(arg0, D_801C6A80, 4, 0, 6, 6, (100 - arg1) * D_801D4B20 + 1.0f);
}
