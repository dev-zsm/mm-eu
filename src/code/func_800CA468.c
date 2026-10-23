#include "types.h"
s32 WaterBox_GetLightSettingIndex(s32 a0, u8 *a1) { u32 x = *(u32 *)(a1 + 0xC); x = x >> 8; return x & 0x1F; }
