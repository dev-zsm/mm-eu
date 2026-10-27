// FLAGS: -O1 -g0 -mips2
#include "types.h"

void View_SetViewport(s32, s32 *);
void View_ApplyOrthoToOverlay(s32);

void func_801172DC(s32 arg0) {
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    sp1C = 0xF0; sp24 = 0x140; sp18 = 0; sp20 = 0; // matching: one source line keeps the ROM store order
    View_SetViewport(arg0, &sp18);
    View_ApplyOrthoToOverlay(arg0);
}
