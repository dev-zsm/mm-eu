// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0291.h"

void func_800B680C();
void func_809F0CA0();

void func_800013E4(u8 *arg0, s32 arg1) {
    s16 v;

    M2C_FIELD(arg0, void (**)(u8 *, s32), 0x144)(arg0, arg1);
    func_800B680C(arg0);
    v = M2C_FIELD(arg0, s16 *, 0x300);
    if (v != 0) {
        M2C_FIELD(arg0, s16 *, 0x300) = v - 1;
    }
    func_809F0CA0(arg0, arg1);
}
