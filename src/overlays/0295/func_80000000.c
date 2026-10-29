#include "types.h"

void func_80000000(s16 *a0, u8 *a1, s32 a2) {
    if (a2 < 0x40) {
        if (a1[a2] != 0) {
            a0[a2] = 0;
        }
    }
}
