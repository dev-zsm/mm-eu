#include "types.h"
#include "m2c_compat.h"
extern void (*D_80BFF8EC[])(u8 *);

void func_80001744(u8 *a) {
    if (M2C_FIELD(a, s32 *, 0x154) != -1 && (M2C_FIELD(a, u32 *, 0x164) & 1)) {
        D_80BFF8EC[M2C_FIELD(a, s32 *, 0x148)](a);
    }
}
