// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80AD5208;

void func_8000034C(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x170) = 5;
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80AD5208;
}
