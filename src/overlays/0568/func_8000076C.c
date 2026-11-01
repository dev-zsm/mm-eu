// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "overlays/0568.h"

extern M2C_UNK D_80BB46FC;

void func_8000076C(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x316) = 0x63;
    M2C_FIELD(arg0, s16 *, 0x314) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80BB46FC;
}
