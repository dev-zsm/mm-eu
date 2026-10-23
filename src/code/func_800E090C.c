#include "types.h"
extern void Collider_InitBase();
s32 Collider_InitJntSph(void *a0, u8 *a1) {
    Collider_InitBase(a0, a1);
    *(s32 *)(a1 + 0x18) = 0;
    *(s32 *)(a1 + 0x1C) = 0;
    return 1;
}
