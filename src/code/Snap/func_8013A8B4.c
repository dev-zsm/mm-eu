// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

s16 Snap_AbsS(s16 val) { s32 v; if (val >= 0) { v = val; } else { v = -val; } return v; }
