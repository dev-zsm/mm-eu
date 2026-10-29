#include "types.h"

extern void func_808814C4();

void func_800067E0(void *a0, void *a1, s32 a2) {
    func_808814C4(a0, a1);
    *(s32 *)((u8 *)a0 + 0x380) = 2;
    *(u16 *)((u8 *)a0 + 0x384) = *(u16 *)((u8 *)a0 + 0x384) & 0xFFFE;
}
