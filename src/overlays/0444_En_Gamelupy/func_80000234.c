// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0444.h"

extern M2C_UNK D_80ADB6D8;

void EnGamelupy_SetupIdle(EnGamelupy *this) {
    M2C_FIELD(this, M2C_UNK **, 0x190) = &D_80ADB6D8;
}
