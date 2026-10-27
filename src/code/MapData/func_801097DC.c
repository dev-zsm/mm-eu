// FLAGS: -O1 -g3 -mips2
#include "types.h"
extern u8 D_801BFCC6[];
void func_801097DC(s32 a0, s32 *a1) { *a1 = *(u8 *)(D_801BFCC6 + a0 * 10); }
