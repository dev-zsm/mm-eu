// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern u8 D_801EB7E0[];
void Play_EnableMotionBlur(s32 a0) { u8 **p = (u8 **)&D_801EB7E0; *(s16 *)(*p + 0x188) = a0; *(s16 *)(*p + 0x18A) = 1; }
