// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s8 D_801EE354;

void Rumble_StateReset(void) {
    D_801EE354 = 2;
}
