#include "types.h"
extern u8 func_80948050[];
void func_80001E60(u8 *a0) {
    *(s16 *)(*(u8 **)(a0 + 0x124) + 0x118) = 10;
    *(s32 *)(a0 + 0x1D4) = (s32)func_80948050;
}
