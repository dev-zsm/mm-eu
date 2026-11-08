#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0415.h"
void func_800E7BB8(u8 *a, u8 *c);
void func_800B64E0(u8 *a, s32 b);

void func_80000418(u8 *a, s32 b) {
    func_800E7BB8(a, a + 0x144);
    M2C_FIELD(a, void (**)(u8 *, s32), 0x1A0)(a, b);
    func_800B64E0(a, M2C_FIELD(a, s32 *, 0xC4));
}
