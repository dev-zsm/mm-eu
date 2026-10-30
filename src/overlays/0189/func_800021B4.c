#include "types.h"
extern u8 D_80956510;
extern f32 D_80956E08;
void func_800021B4(u8 *a) {
    *(f32 *)(a + 0xC4) = D_80956E08;
    *(s32 *)(a + 0x13C) = 0;
    *(s32 *)(a + 4) |= 0x8000000;
    *(s16 *)(a + 0x196) = 5;
    *(u8 **)(a + 0x148) = &D_80956510;
}
