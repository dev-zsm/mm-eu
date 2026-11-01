// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0119.h"

void func_800000A8(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x164) = 0;
}
