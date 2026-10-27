#include "types.h"
s32 Camera_IsClimbingLedge(u8 *a0) {
    u8 *v1 = *(u8 **)(a0 + 0x90);
    if (v1 == *(u8 **)(*(u8 **)(a0 + 0x8C) + 0x1CCC)) {
        return *(u32 *)(v1 + 0xA6C) & 4;
    }
    return 0;
}
