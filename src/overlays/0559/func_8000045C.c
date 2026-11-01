// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0559.h"

extern M2C_UNK D_80BAA140;

void func_8000045C(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x234) = &D_80BAA140;
}
