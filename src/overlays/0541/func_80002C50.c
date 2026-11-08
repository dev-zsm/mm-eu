#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0541.h"
void func_80B8CB68(u8 *a, s32 b);
void func_80137070(u8 *a);

void func_80002C50(u8 *a, s32 b) {
    M2C_FIELD(a, void (**)(u8 *, s32), 0x1D4)(a, b);
    func_80B8CB68(a, b);
    func_80137070(a + 0x190);
}
