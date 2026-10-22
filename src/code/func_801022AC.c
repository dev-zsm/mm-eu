// FLAGS: -O2 -g3 -mips2
#include "types.h"

void LightContext_InitList(s32, s32);
void LightContext_SetAmbientColor(s32, s32, s32, s32);
void LightContext_SetFog(s32, s32, s32, s32, s32, s32);
void func_800897D0(void *, s32);
extern u8 D_801EC7F0[];

void LightContext_Init(s32 a0, s32 arg1) {
    LightContext_InitList(a0, arg1);
    LightContext_SetAmbientColor(arg1, 0x50, 0x50, 0x50);
    LightContext_SetFog(arg1, 0, 0, 0, 0x3E4, 0x3200);
    func_800897D0(D_801EC7F0, 0x188);
}
