#include "types.h"

extern void func_800B6564();
extern u8 D_8092A024;

void func_80000000(u8 *a0, s32 a1) {
    *(u8 **)(a0 + 0x144) = &D_8092A024;
    func_800B6564(a0, 0x3E4CCCCD);
}
