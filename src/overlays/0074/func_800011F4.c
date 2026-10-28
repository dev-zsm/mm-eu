#include "types.h"
extern u8 D_80897864[];
void func_800011F4(u8 *a0) {
    *(s32 *)(a0 + 0x2A8) = (s32)D_80897864;
    *(f32 *)(a0 + 0x70) = 2.5f;
}
