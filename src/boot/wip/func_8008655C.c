// FLAGS: -O2 -g0
#include "types.h"

extern void func_80086380(u32 a0);

void func_8008655C(u32 a0, s32 a1, s32 a2, void (*a3)(u32, s32), s32 a4) {
    u32 base;
    u32 end;
    u32 p;
    s32 size;

    base = a0;
    size = a2;
    if (a0 != 0) {
        if (a3 != NULL) {
            end = a0;
            p = a0 + a1 * size;
            while (end < p) {
                p -= size;
                a3(p, 2);
            }
        }
        if (a4 != 0) {
            func_80086380(base);
        }
    }
}
