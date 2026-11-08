// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0448.h"

extern M2C_UNK D_80AE1904;
extern M2C_UNK D_80AE1BC4;

void EnGakufu_DisplayOnTimer(EnGakufu *this, PlayState *play) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(this, s16 *, 0x14);
    if (temp_v0 > 0) {
        M2C_FIELD(this, M2C_UNK **, 0x13C) = &D_80AE1BC4;
        M2C_FIELD(this, s16 *, 0x14) = (s16) (temp_v0 - 1);
        return;
    }
    M2C_FIELD(this, M2C_UNK **, 0x13C) = NULL;
    M2C_FIELD(this, s16 *, 0x14) = 0;
    M2C_FIELD(this, M2C_UNK **, 0x150) = &D_80AE1904;
}
