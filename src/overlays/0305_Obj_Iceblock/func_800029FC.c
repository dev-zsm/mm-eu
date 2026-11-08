// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0305.h"

extern M2C_UNK D_80A0A7D8;

void func_800029FC(ObjIceblock *this) {
    M2C_FIELD(this, M2C_UNK **, 0x1A8) = &D_80A0A7D8;
    M2C_FIELD(this, s16 *, 0x2A0) = 2;
}
