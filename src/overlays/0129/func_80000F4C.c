// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern void (*D_808F92A4[])();

void func_80000F4C(u8 *arg0) {
    s16 v = M2C_FIELD(arg0, s16 *, 0x1C);
    s32 t = v & 0xFF;
    void (*fn)();

    M2C_FIELD(arg0, s32 *, 0x15C) = t;
    M2C_FIELD(arg0, s32 *, 0x160) = (v & 0xFF00) >> 8;
    if (t >= 0xA) {
        M2C_FIELD(arg0, s32 *, 0x15C) = 0;
    }
    fn = D_808F92A4[M2C_FIELD(arg0, s32 *, 0x15C)];
    if (fn != NULL) {
        fn();
    }
}
