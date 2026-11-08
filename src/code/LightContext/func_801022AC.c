// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

void LightContext_SetFog(s32, s32, s32, s32, s32, s32);
void func_800897D0(void *, s32);
extern u8 D_801EC7F0[];

void LightContext_Init(struct PlayState *play, struct LightContext *lightCtx) {
    LightContext_InitList(play, lightCtx);
    LightContext_SetAmbientColor(lightCtx, 0x50, 0x50, 0x50);
    LightContext_SetFog(lightCtx, 0, 0, 0, 0x3E4, 0x3200);
    func_800897D0(D_801EC7F0, 0x188);
}
