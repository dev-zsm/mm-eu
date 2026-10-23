#include "types.h"
extern u8 D_801BFCC7[];
u8 MapData_GetMapIColorIndex(s32 a0) { return *(u8 *)(D_801BFCC7 + a0 * 10); }
