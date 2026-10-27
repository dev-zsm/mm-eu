// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern u8 D_801BE6F0;

u8 Environment_GetSandstormColorIndex(void) {
    return D_801BE6F0;
}
