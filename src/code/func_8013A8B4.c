// FLAGS: -O2 -g3 -mips2
#include "types.h"

s16 Snap_AbsS(s16 arg0) { s32 v; if (arg0 >= 0) { v = arg0; } else { v = -arg0; } return v; }
