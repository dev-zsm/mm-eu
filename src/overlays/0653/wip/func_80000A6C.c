#include "types.h"
extern u8 D_80C0551C[];
void func_80000A6C(u8 *a) { *(s16 *)(a + 0x3E0) = 0; *(void **)(a + 0x228) = D_80C0551C; *(f32 *)(a + 0x70) = 0.0f; }
