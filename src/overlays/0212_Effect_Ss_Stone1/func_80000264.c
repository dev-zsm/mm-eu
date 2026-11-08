// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0212.h"

extern u8 *D_801EB7E0;

void EffectSsStone1_Update(PlayState *play, u32 index, void *this) {
    if ((M2C_FIELD(this, s16 *, 0x5C) == 6) && (M2C_FIELD(this, s16 *, 0x40) != 0)) {
        M2C_FIELD(D_801EB7E0, s16 *, 0xD38) = 0;
    }
}
