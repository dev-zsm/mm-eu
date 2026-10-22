// FLAGS: -O2 -g0 -mips2
#include "types.h"
f32 roundf(f32 x) { return (f32)(s32)(x + 0.5f); }
