// FLAGS: -O2 -g0
#include "types.h"
extern u32 D_8009D120;
f32 func_80087128(u32 *a)
{
  u32 v = ((*a) * 0x19660D) + 0x3C6EF35F;
  u32 bits = (v >> 9) | 0x3F800000;
 *a = v; D_8009D120 = bits;
  return (*((f32 *) (&D_8009D120))) - 1.0f;
}
