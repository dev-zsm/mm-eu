#include "types.h"
void func_800001BC(u8 *a0, s32 a1) {
    if (a1 & 0x80) {
        a0[0x11] = (a1 >> 1) & 3;
        a0[0x12] = a1 & 1;
        return;
    }
    if (a1 == 1) {
        a0[0x10] = 1;
        return;
    }
    a0[0x10] = 0;
}
