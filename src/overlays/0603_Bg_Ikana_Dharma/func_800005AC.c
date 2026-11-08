// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0603.h"

extern M2C_UNK D_80BD15A8;

void BgIkanaDharma_SetupWaitForCutsceneToEnd(BgIkanaDharma *this) {
    M2C_FIELD(this, s8 *, 0x1AC) = 0xA;
    M2C_FIELD(this, M2C_UNK **, 0x1A8) = &D_80BD15A8;
}
