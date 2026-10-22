// FLAGS: -O2 -g0 -mips2
#include "types.h"
f64 round(f64 x) { return (f64)(s32)(x + 0.5); }
