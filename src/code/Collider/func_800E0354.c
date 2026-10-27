#include "types.h"

s32 Collider_SetBaseToActor(s32 arg0, u8 *dst, u8 *src) {
    *(u32 *)dst = *(u32 *)src;
    dst[0x10] = src[4];
    dst[0x11] = src[5];
    dst[0x12] = src[6];
    dst[0x13] = 0x10;
    dst[0x15] = src[7];
    return 1;
}
