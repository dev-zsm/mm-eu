#include "types.h"

void func_8000003C(s16 *a, s16 b) {
    s32 x = *a;
    s32 y = -b;
    if (b < x) {
        *a = b;
    } else if (x < y) {
        *a = y;
    }
}
