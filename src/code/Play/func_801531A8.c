// FLAGS: -O1 -g0 -mips2
#include "types.h"
#include "generated/code_funcs.h"
void View_SetViewport(s32, void *);
void func_801531A8(s32 a0) {
    struct { s32 a, b, c, d; } r;
    r.a = 0; r.c = 0; r.b = 0xF0; r.d = 0x140;
    View_SetViewport(a0, &r);
    View_ApplyOrthoToOverlay(a0);
}
