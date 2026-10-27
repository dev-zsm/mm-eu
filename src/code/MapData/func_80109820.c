// FLAGS: -O1 -g3 -mips2
#include "types.h"
extern u8 D_801BFCC8[];
s16 MapData_GetMapIScale(s32 a0) { return *(s16 *)(D_801BFCC8 + a0 * 10); }
