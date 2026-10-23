// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
f32 Math3D_Dist1DSq(f32 a, f32 b) { return a * a + b * b; }
