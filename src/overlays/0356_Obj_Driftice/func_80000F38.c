// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0356.h"

extern M2C_UNK D_80A4C224;

void func_80000F38(ObjDriftice *this) {
    M2C_FIELD(this, s32 *, 0x24C) = 0xA;
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80A4C224;
}
