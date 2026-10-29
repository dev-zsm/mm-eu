#include "types.h"

extern void func_800B8C4C();

void func_80000320(u8 *a) {
    if (((s8 *)a)[0x165] <= 0) {
        func_800B8C4C(a, 0x28BA);
    }
}
