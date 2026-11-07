#include "types.h"
#include "m2c_compat.h"
void func_800B8C4C(u8 *a, u16 b);

void func_80000000(u8 *a, u16 b) {
    if (M2C_FIELD(a, s8 *, 0x1B2) <= 0) {
        func_800B8C4C(a, b);
    }
}
