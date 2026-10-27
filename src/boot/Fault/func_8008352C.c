// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern void osViSetYScale(f32 a0);
extern void osViSetMode(void *a0);
extern void osViSetSpecialFeatures(s32 a0);
extern void osViBlack(s32 a0);
extern s32 func_8008ABB0(void);
extern void osViSwapBuffer(s32 a0);
extern void FaultDrawer_SetDrawerFrameBuffer(s32 a0, s32 a1, s32 a2);
extern u8 D_800981B0[];
extern void *D_8009C220;
extern s32 D_80000318;
void Fault_DisplayFrameBuffer(void) {
    s32 a;
    s32 v;
    osViSetYScale(1.0f);
    osViSetMode(D_800981B0);
    osViSetSpecialFeatures(0x42);
    osViBlack(0);
    v = *(s32 *)((u8 *)D_8009C220 + 0x844);
    if (v != 0) {
        a = v;
    } else {
        v = func_8008ABB0();
        a = v;
        if (v == 0x80000000) {
            a = (D_80000318 | 0x80000000) + 0xFFFDA800;
        }
    }
    osViSwapBuffer(a);
    FaultDrawer_SetDrawerFrameBuffer(a, 0x140, 0xF0);
}
