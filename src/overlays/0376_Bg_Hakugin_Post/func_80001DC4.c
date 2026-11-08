// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0376.h"

extern M2C_UNK D_80A81728;

void func_80001DC4(BgHakuginPost *this) {
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80A81728;
}
