// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern u16 D_801F4AE0;
void Audio_ResetRequestedSceneSeqId(void) { D_801F4AE0 = 0xFFFF; }
