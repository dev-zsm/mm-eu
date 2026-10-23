// FLAGS: -O2 -g3 -mips2
#include "types.h"
s32 WaterBox_GetBgCamIndex(s32 a0, u8 *a1) { u32 x; x = *(u32 *)(a1 + 0xC); return x & 0xFF; }
