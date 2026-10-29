#include "types.h"

extern void func_80830B44();

void func_80003C9C(void *a0, u8 *a1) {
    s32 sp1C;

    sp1C = a1[0x275];
    a1[0x275] = 0;
    func_80830B44(a0);
    a1[0x275] = sp1C;
}
