// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_800003C0(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x2B8) = 0;
    M2C_FIELD(arg0, s16 *, 0x2BC) = 0;
    M2C_FIELD(arg0, s16 *, 0x2BA) = 0;
    M2C_FIELD(arg0, s16 *, 0x29E) = 0;
    M2C_FIELD(arg0, s16 *, 0x290) = 0;
}
