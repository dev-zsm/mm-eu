// FLAGS: -O2 -g0 -mips2
#include "types.h"

s32 osAiGetLength(void) {
    return *(s32 *)0xA4500004;
}
