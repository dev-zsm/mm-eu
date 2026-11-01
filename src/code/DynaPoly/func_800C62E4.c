// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

void DynaPoly_InvalidateLookup(s32 arg0, u8 *arg1) {
    *arg1 |= 1;
}
