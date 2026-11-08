#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0465.h"
void func_800B6490(u8 *a);
void func_80AFF378(u8 *a, s32 b, u8 *c);

void func_800018F0(u8 *a, s32 b) {
    M2C_FIELD(a, s16 *, 0x192) += 1;
    if (M2C_FIELD(a, s16 *, 0x192) == 0x20) {
        func_800B6490(a);
    } else {
        func_80AFF378(a, M2C_FIELD(a, s16 *, 0x192), a + 0x24);
    }
}
