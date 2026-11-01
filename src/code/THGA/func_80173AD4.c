// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern void *THGA_AllocDisplayList();
void *THGA_AllocGfx(void *a0) { return THGA_AllocDisplayList(a0, 1); }
