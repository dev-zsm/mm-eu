// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "generated/code_funcs.h"
void *THGA_AllocGfx(void *a0) { return THGA_AllocDisplayList(a0, 1); }
