#include "types.h"

void func_8017A1B0(u16 *a0, s32 a1, s32 a2, s32 a3) {
    u16 *p;
    if (a3 & 1) {
        p = (u16 *)((u8 *)a0 + a1 * 2);
        p[a2 * 320] = a3;
    }
}
