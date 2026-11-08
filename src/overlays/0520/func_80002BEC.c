#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0520.h"
void func_80B75AB8(u8 *a, s32 b);
void func_80B75998(u8 *a, s32 b);

void func_80002BEC(u8 *a, s32 b) {
    M2C_FIELD(a, void (**)(u8 *, s32), 0x188)(a, b);
    func_80B75AB8(a, b);
    func_80B75998(a, b);
}
