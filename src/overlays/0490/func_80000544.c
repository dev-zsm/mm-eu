#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0490.h"
s32 func_80137C58(u8 *a, f32 b);
void func_800B8C4C(u8 *a, s32 b);

void func_80000544(u8 *a) {
    if (func_80137C58(a + 0x190, 0.0f) != 0 || func_80137C58(a + 0x190, 4.0f) != 0) {
        func_800B8C4C(a, 0x39F8);
    }
}
