#include "types.h"
#include "m2c_compat.h"
void func_80137070(u8 *a);
void func_80B03908(u8 *a);

void func_80001198(u8 *a, s32 b) {
    f32 v = M2C_FIELD(a, f32 *, 0x15C);

    func_80137070(a + 0x144);
    if (M2C_FIELD(a, f32 *, 0x2D8) <= v) {
        func_80B03908(a);
    }
}
