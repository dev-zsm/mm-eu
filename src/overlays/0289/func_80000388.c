#include "types.h"
extern u8 D_809D71F8[];
void func_80000388(u8 *a0) {
    *(s32 *)(a0 + 0x198) = (s32)D_809D71F8;
    *(f32 *)(a0 + 0xA28) = 0.0f;
    *(f32 *)(a0 + 0x1AC) = 0.0f;
}
