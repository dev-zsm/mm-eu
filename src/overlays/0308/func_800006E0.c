#include "types.h"
#include "m2c_compat.h"
void func_80A110DC(u8 *a);

void func_800006E0(u8 *a, s32 b) {
    u8 *p = M2C_FIELD(a, u8 **, 0x120);
    s16 v = M2C_FIELD(a, s16 *, 0x1D8);

    if (M2C_FIELD(a, s16 *, 0x1EE) < v || M2C_FIELD(p, s16 *, 0x26A) != 1) {
        func_80A110DC(a);
        v = M2C_FIELD(a, s16 *, 0x1D8);
    }
    M2C_FIELD(a, s16 *, 0x1D8) = v + 1;
}
