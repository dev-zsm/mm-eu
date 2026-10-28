// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80002928(u8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x266);
    switch (temp_v0) {                              /* irregular */
    case 1:
        M2C_FIELD(arg0, s16 *, 0x264) = 2;
        break;
    case 2:
        M2C_FIELD(arg0, s16 *, 0x264) = 1;
        break;
    case 40:
        M2C_FIELD(arg0, s16 *, 0x266) = 0;
        /* fallthrough */
    default:
        M2C_FIELD(arg0, s16 *, 0x264) = 0;
        break;
    }
    M2C_FIELD(arg0, s16 *, 0x266) = (s16) (M2C_FIELD(arg0, s16 *, 0x266) + 1);
}
