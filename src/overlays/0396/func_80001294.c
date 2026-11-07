#include "types.h"
#include "m2c_compat.h"
extern u8 D_80AA3CBC[];
void func_80AA2A5C(u8 *a, s32 b);

void func_80001294(u8 *a) {
    if (M2C_FIELD(a, s16 *, 0x332) != 2) {
        func_80AA2A5C(a, 1);
    } else {
        func_80AA2A5C(a, 0xF);
    }
    M2C_FIELD(a, void **, 0x188) = D_80AA3CBC;
}
