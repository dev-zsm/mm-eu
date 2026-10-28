// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern u16 *D_80862264;

void func_8000CAE0(u8 *arg0) {
    s8 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s8 *, 0xADC);
    if ((temp_v0 > 0) && (~(*D_80862264 | ~0x4000) != 0)) {
        M2C_FIELD(arg0, s8 *, 0xADC) = (s8) -temp_v0;
    }
}
