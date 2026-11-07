#include "types.h"
#include "m2c_compat.h"
void func_80ADCBC8(u8 *a, s32 b);

s32 func_80001244(u8 *a, s32 b) {
    s32 v = M2C_FIELD(a, s32 *, 0x384);

    if (v != 7) {
        if (v == 0xA) {
            func_80ADCBC8(a, 9);
        }
    } else {
        func_80ADCBC8(a, 0);
    }
    return 1;
}
