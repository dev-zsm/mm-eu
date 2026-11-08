// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_808C99D8();
extern u8 D_808CA638;

void func_80000E58(u8 *arg0) {
    s32 i;
    u8 *p;

    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    func_808C99D8(arg0, 1);
    i = 0;
    p = arg0;
    do {
        i++;
        p += 0x24;
        M2C_FIELD(p, s16 *, 0x15E) = 0;
    } while (i != 3);
    M2C_FIELD(arg0, u8 **, 0x144) = &D_808CA638;
}
