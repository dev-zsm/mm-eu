#include "types.h"
extern u8 D_80BEFB04[];
void func_80000604(u8 *a) { *(void **)(a + 0x160) = D_80BEFB04; *(f32 *)(a + 0x68) = 5.0f; }
