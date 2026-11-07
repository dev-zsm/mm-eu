#include "types.h"
#include "m2c_compat.h"
s32 func_80AA61D4(u8 *a, s32 b);
void func_80AA661C(u8 *a);

void func_800007AC(u8 *a, s32 b) {
    M2C_FIELD(a, void (**)(u8 *, s32), 0x188)(a, b);
    if (func_80AA61D4(a, b) != 0) {
        func_80AA661C(a);
    }
}
