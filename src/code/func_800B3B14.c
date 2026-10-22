// FLAGS: -O2 -g3 -mips2
#include "types.h"

void ActorShape_Init(u8 *p, f32 a, s32 b, f32 c) {
    *(f32 *)(p + 0x8) = a;
    *(s32 *)(p + 0xC) = b;
    *(f32 *)(p + 0x10) = c;
    *(u8 *)(p + 0x14) = 0xFF;
}
