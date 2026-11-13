#include "types.h"
#include "m2c_compat.h"

extern u8 D_8085C08C[];

s8 func_80001A94(u8 *arg0, s32 arg1) {
    if (arg1 >= 0xFD) {
        return 0;
    }
    if (arg1 == 0xFC) {
        return 1;
    }
    if (arg1 == 0x5C) {
        return 2;
    }
    if ((arg1 == 0x4D) && (M2C_FIELD(arg0, u8 *, 0x14B) == 2)) {
        return 8;
    }
    return D_8085C08C[arg1];
}
