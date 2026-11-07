#include "types.h"
#include "m2c_compat.h"
extern u8 D_80BF8FD0[];
s32 func_80087010(void);

void func_800008AC(u8 *a) {
    s32 r = func_80087010() & 3;

    M2C_FIELD(a, s32 *, 0x218) = r;
    M2C_FIELD(a, s16 *, 0x2FC) = 0;
    M2C_FIELD(((u8 **)(a + 0x208))[r], u8 *, 0) |= 1;
    M2C_FIELD(a, void **, 0x1D4) = D_80BF8FD0;
}
