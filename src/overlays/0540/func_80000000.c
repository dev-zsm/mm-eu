#include "types.h"
extern void (*D_80B89DBC[])();
void func_80000000(u8 *a0, s32 a1, s32 a2) {
    a0[0x2B7] = 0;
    a0[0x2B0] = a2;
    D_80B89DBC[(u8)a2](a0, a1, a2);
}
