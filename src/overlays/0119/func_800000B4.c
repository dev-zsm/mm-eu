// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80137C58(u8 *, f32);
void func_808E061C();

void func_800000B4(u8 *arg0, s32 arg1) {
    u8 *p = M2C_FIELD(arg0, u8 **, 0x120);

    if (p != NULL) {
        if (func_80137C58(p + 0x15C, 10.0f) != 0) {
            func_808E061C(arg0, arg1, M2C_FIELD(p, s32 *, 0x174));
        }
    }
}
