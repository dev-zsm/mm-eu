// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0501.h"

extern M2C_UNK D_80B529DC;

void func_800000B8(BgHakaCurtain *this) {
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80B529DC;
}
