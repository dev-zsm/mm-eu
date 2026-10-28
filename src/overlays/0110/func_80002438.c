// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_808D21C4;

void func_80002438(u8 *arg0) {
    M2C_FIELD(arg0, u8 *, 0x364) = (u8) (M2C_FIELD(arg0, u8 *, 0x364) & ~3);
    M2C_FIELD(arg0, u8 *, 0x365) = (u8) (M2C_FIELD(arg0, u8 *, 0x365) & ~3);
    M2C_FIELD(arg0, u8 *, 0x366) = (u8) (M2C_FIELD(arg0, u8 *, 0x366) & ~3);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808D21C4;
}
