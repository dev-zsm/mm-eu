// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80BB90F8;

void func_800002AC(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x166) = 0x63;
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80BB90F8;
}
