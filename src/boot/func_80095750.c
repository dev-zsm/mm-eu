// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern void *D_800982B0;

void *__osViGetCurrentContext(void) {
    return D_800982B0;
}
