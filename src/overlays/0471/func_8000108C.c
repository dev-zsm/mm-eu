#include "types.h"
#include "m2c_compat.h"
void func_800B8C4C(u8 *a, s32 b);

void func_8000108C(u8 *a) {
    s16 v = M2C_FIELD(a, f32 *, 0x164);

    if (v == 1 || v == 7) {
        func_800B8C4C(a, 0x28EF);
    }
}
