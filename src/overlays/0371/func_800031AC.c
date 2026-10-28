// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_800031AC(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x3D8) = 2;
}
