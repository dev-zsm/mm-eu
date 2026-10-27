// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern s32 THA_AllocHead();
s32 THA_AllocHeadByte(s32 a0) { return THA_AllocHead(a0, 1); }
