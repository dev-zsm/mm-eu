#include "types.h"

extern void func_8017A1E0();

void func_8017A220(s32 a0, s32 a1, s32 a2, s32 a3, s32 rows, u8 *arg5) {
    s32 y;
    s32 x;
    s32 v;
    u8 *data;

    data = arg5;
    for (y = 0; y < rows; y++) {
        for (x = 0; x < a3; x += 2) {
            v = *data;
            func_8017A1E0(a0, a1 + x, a2 + y, v >> 4);
            v = *data;
            func_8017A1E0(a0, a1 + x + 1, a2 + y, v & 0xF);
            data++;
        }
    }
}
