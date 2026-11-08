// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0175.h"

void func_800B6490();
s32 func_800F1E2C();

void func_80001AB4(u8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s8 *, 0x38) < 0) {
        func_800B6490();
        return;
    }
    if (func_800F1E2C() != M2C_FIELD(arg0, s8 *, 0x38)) {
        func_800B6490();
    }
}
