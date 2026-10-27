// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern void Collider_SetLinePoints(s32 a0, void *a1, void *a2, void *a3);
s32 Collider_SetLine(s32 a0, u8 *a1, u8 *a2) {
    *(u16 *)(a1 + 0x18) = *(u16 *)(a2 + 0x18);
    Collider_SetLinePoints(a0, a1, a2, a2 + 0xC);
    return 1;
}
