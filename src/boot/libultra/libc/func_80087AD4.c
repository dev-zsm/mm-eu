// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern void vaprintf(void *a0, s32 a1, void *a2);

void aprintf(void *a0, s32 a1, ...) {
    vaprintf(a0, a1, (char *)&a1 + 4);
}
