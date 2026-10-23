// FLAGS: -O2 -g0 -mips2
// best attempt: ~4 diffs (reg v1 vs v0 for table ptr, f18 vs f16, missing nop before loop)
#include "types.h"
extern f32 D_80099350[];
f32 Math_FAtanTaylorQF(f32 x) { f32 poly = x; f32 sq = x * x; f32 exp = x * sq; f32 term, nx; s32 i; for (i = 0; ; i++) { term = exp * D_80099350[i]; nx = poly + term; if (poly == nx) break; exp *= sq; poly = nx; } return poly; }
