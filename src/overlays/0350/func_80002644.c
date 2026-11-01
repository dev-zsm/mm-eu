// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "overlays/0350.h"

extern M2C_UNK D_80A42524;
extern M2C_UNK D_80A43620;

void func_80002644(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80A43620;
    M2C_FIELD(arg0, M2C_UNK **, 0x190) = &D_80A42524;
}
