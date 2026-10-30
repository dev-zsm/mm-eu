#include "types.h"
extern s16 D_801EC702;
void func_800014D8(u8 *a, s32 b) {
    s32 t;
    t = (*(s16 *)(a + 0x1C) >> 10) * 100;
    if (t > 0) {
        D_801EC702 = t;
    }
}
