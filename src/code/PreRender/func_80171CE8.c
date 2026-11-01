// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "generated/code_funcs.h"
void PreRender_RestoreFramebuffer(s32 *a0, s32 a1) {
    s32 v = a0[5];
    PreRender_RestoreBuffer(a0, a1, v, a0[4]);
}
