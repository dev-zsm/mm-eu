// FLAGS: -O1 -g0 -mips2
// best attempt: 2 instr differ (order of 'or s0,v0,zero' vs 'addu at,at,t1' before the second jal)
#include "types.h"
extern s32 D_80097FD0; extern s32 D_80097FD4; s32 __osDisableInt(void); void __osRestoreInt(s32 m); void __osSetHWIntrRoutine(s32 i, s32 a, s32 b) { register s32 saved = __osDisableInt(); *(s32 *)((u8 *)&D_80097FD0 + i * 8) = a; *(s32 *)((u8 *)&D_80097FD4 + i * 8) = b; __osRestoreInt(saved); }
