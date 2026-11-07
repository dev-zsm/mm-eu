#include "types.h"
#include "m2c_compat.h"
void func_80AB3D7C(u8 *a, s32 b);
void func_80AB3CF4(u8 *a);

void func_80000E6C(u8 *a, s32 b) {
    M2C_FIELD(a, void (**)(u8 *, s32), 0x15C)(a, b);
    func_80AB3D7C(a, b);
    if (M2C_FIELD(a, s16 *, 0x30A) == 1) {
        func_80AB3CF4(a);
    }
}
