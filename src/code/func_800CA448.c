// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern s32 WaterBox_GetBgCamSetting();
s32 WaterBox_GetSceneBgCamSetting(s32 a0, s32 a1) { return WaterBox_GetBgCamSetting(a0, a1, 0x32); }
