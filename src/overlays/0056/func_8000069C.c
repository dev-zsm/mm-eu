// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0056.h"

s32 func_8082D77C();
void func_801A04E8();

void func_8000069C(u8 *arg0, s32 arg1) {
    s32 v;

    if (M2C_FIELD(arg0, u8 *, 0x153) == 0x14) {
        v = 0x8CE;
    } else {
        v = func_8082D77C(arg0, 0x800);
    }
    func_801A04E8(arg0 + 0xEC, v & 0xFFFF, arg1);
}
