// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern s32 PreRender_CopyImage();
void PreRender_RestoreBuffer(s32 a0, s32 a1, s32 a2, s32 a3) { PreRender_CopyImage(a0, a1, a2, a3, 0); }
