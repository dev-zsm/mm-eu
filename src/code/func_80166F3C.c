// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern u8 *D_801EB7E0;
void Play_EnableMotionBlurPriority(s32 a0) { *(s16 *)(*(u8 **)&D_801EB7E0 + 0x18C) = a0; *(s16 *)(*(u8 **)&D_801EB7E0 + 0x18E) = 1; }
