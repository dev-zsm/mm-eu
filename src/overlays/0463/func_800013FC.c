#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0463.h"
void func_80137070(u8 *a);
void func_80AFCC7C(u8 *a, s32 b);

void func_800013FC(u8 *a, s32 b) {
    s16 v;

    func_80137070(a + 0x144);
    v = M2C_FIELD(a, s16 *, 0x28C);
    if (v > 0) {
        M2C_FIELD(a, s16 *, 0x28C) = v - 1;
    } else {
        func_80AFCC7C(a, b);
    }
}
