#include "types.h"
#include "m2c_compat.h"
void func_80AA49DC(u8 *a, s32 b, s32 c);

void func_80002034(u8 *a) {
    if (M2C_FIELD(a, s16 *, 0x332) != 2) {
        func_80AA49DC(a, 0, 0);
    } else {
        func_80AA49DC(a, 1, 2);
    }
}
