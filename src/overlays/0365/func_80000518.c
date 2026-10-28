#include "types.h"
extern u8 D_80A5C578[];
void func_80000518(u8 *a0) {
    *(s16 *)(a0 + 0x284) = 0;
    *(s32 *)(a0 + 0x36C) = 2;
    *(s32 *)(a0 + 0x278) = (s32)D_80A5C578;
}
