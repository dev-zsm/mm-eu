// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u8 pad0[0x11F]; u8 b11F; u8 pad1[0x6C]; u8 b18C; u8 b18D; u8 pad2[0x1AA]; u8 b338; } S0068;

void func_80000240(S0068 *a0) {
    a0->b18D = 3;
    a0->b338 = 0;
    a0->b18C = 0;
    a0->b11F = 0x12;
}
