#include "types.h"
#include "m2c_compat.h"
void func_80B1C9D0(u8 *a, s32 b);
void func_80B1C990(u8 *a);

void func_800013D4(u8 *a, s32 b) {
    M2C_FIELD(a, void (**)(u8 *, s32), 0x144)(a, b);
    func_80B1C9D0(a, b);
    func_80B1C990(a);
}
