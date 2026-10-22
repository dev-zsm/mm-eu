// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern u8 D_801BE6F4;

u8 Environment_GetNextSandstormColorIndex(void) {
    return D_801BE6F4;
}
