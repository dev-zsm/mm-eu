// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct { u8 b[4]; u16 h; } C6;
void Actor_SetWorldRotToShape(u8 *a0) { *(C6 *)(a0 + 0x30) = *(C6 *)(a0 + 0xBC); }
