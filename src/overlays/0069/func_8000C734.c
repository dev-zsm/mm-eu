// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0069.h"

s32 func_80887480();

s32 func_8000C734(u8 *arg0, u8 *arg1) {
    s32 v;

    if (M2C_FIELD(arg0, s32 *, 0x144) != 2) {
        return 0;
    }
    v = M2C_FIELD(arg0, s32 *, 0x20C);
    if (v != 0 && v != 1) {
        return 0;
    }
    return func_80887480(arg0, arg1, M2C_FIELD(arg1, s32 *, 0x1CCC));
}
