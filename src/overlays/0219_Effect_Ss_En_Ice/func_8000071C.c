#include "types.h"
// FLAGS: -O2 -g0 -mips2
typedef struct { u8 p0[0x44]; s16 a44; s16 a46; } S;
void EffectSsEnIce_Update(s32 a0, s32 a1, S *p) { p->a44 = p->a44 + p->a46; }
