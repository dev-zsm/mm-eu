#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0396.h"
extern u8 D_80AA3CBC[];
void func_80AA2A5C(u8 *a, s32 b);

void func_80001294(Actor *thisx) {
    if (M2C_FIELD(thisx, s16 *, 0x332) != 2) {
        func_80AA2A5C(thisx, 1);
    } else {
        func_80AA2A5C(thisx, 0xF);
    }
    M2C_FIELD(thisx, void **, 0x188) = D_80AA3CBC;
}
