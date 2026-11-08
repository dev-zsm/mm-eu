#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0383.h"
void func_80137070(u8 *a);

void func_800002E8(u8 *a, s32 b) {
    func_80137070(a + 0x144);
    M2C_FIELD(a, void (**)(u8 *, s32), 0x23C)(a, b);
    M2C_FIELD(a, u16 *, 0x262)++;
}
