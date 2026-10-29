#include "types.h"

extern void func_8087FBEC();

void func_80004DD0(void *a0) {
    func_8087FBEC(a0);
    *(u32 *)((u8 *)a0 + 0x1E8) &= 0xFFFEFFFF;
}
