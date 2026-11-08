// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0148.h"

M2C_UNK func_809138F8();                            /* extern */

void EnHonotrap_EyeAttack(EnHonotrap *this, PlayState *play) {
    if (M2C_FIELD(this, s16 *, 0x220) <= 0) {
        func_809138F8();
    }
}
