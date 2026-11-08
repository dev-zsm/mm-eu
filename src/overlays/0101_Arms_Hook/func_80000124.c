// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0101.h"

void ArmsHook_PullPlayer(ArmsHook *this) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(this, u8 **, 0x120);
    M2C_FIELD(this, u8 **, 0x124) = temp_v0;
    M2C_FIELD(temp_v0, u8 **, 0x120) = this;
}
