// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "overlays/0155.h"

extern M2C_UNK D_80920A60;

void func_80001380(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x16C) = 0;
    M2C_FIELD(arg0, s8 *, 0x16D) = 0;
    M2C_FIELD(arg0, s8 *, 0x16E) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80920A60;
}
