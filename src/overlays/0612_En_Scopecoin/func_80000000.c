// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0612.h"

void EnScopecoin_Spin(EnScopecoin *this, PlayState *play) {
    M2C_FIELD(this, s16 *, 0xBE) = (s16) (M2C_FIELD(this, s16 *, 0xBE) + 0x1F4);
}
