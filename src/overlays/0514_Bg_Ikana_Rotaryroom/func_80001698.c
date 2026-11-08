// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0514.h"

extern M2C_UNK D_80B666AC;

void func_80001698(BgIkanaRotaryroom *this) {
    M2C_FIELD(this, M2C_UNK **, 0x200) = &D_80B666AC;
}
