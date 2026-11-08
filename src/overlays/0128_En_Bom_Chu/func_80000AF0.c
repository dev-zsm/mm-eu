// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0128.h"

M2C_UNK func_800B6490();                            /* extern */

void EnBomChu_WaitForDeath(EnBomChu *this, PlayState *play) {
    if (M2C_FIELD(this, s16 *, 0x14A) == 0) {
        func_800B6490();
    }
}
