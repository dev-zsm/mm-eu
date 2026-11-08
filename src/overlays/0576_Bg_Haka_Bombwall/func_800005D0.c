// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0576.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800F1D6C(s8, u8 *);                  /* extern */

void BgHakaBombwall_EndCutscene(BgHakaBombwall *this, PlayState *play) {
    M2C_FIELD(this, s8 *, 0x1AC) = (s8) (M2C_FIELD(this, s8 *, 0x1AC) - 1);
    if (M2C_FIELD(this, s8 *, 0x1AC) <= 0) {
        func_800F1D6C(M2C_FIELD(this, s8 *, 0x38), this);
        func_800B6490(this);
    }
}
