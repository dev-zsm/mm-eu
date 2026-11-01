// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern s32 Math_Vec3f_Pitch();
s32 Actor_WorldPitchTowardPoint(u8 *a0, u8 *a1) { u8 *p; p = a0; return Math_Vec3f_Pitch(p + 0x24, a1, p); }
