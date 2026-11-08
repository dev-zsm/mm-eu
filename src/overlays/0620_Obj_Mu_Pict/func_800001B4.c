// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0620.h"

extern M2C_UNK D_80BEBA08;

void func_800001B4(ObjMuPict *this) {
    M2C_FIELD(this, M2C_UNK **, 0x144) = &D_80BEBA08;
}
