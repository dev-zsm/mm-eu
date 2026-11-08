// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0407.h"

void EffectSsSbn_Update(PlayState *play, u32 index, void *this) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(this, s16 *, 0x5C);
    if (temp_v0 < 0xA) {
        M2C_FIELD(this, s16 *, 0x46) = (s16) (M2C_FIELD(this, s16 *, 0x46) - 0x14);
        return;
    }
    if (temp_v0 >= 0x2D) {
        if (temp_v0 < 0x55) {
            M2C_FIELD(this, s16 *, 0x50) = (s16) (M2C_FIELD(this, s16 *, 0x50) + 0xC);
            M2C_FIELD(this, s16 *, 0x48) = (s16) (M2C_FIELD(this, s16 *, 0x48) - M2C_FIELD(this, s16 *, 0x4A));
            return;
        }
        M2C_FIELD(this, s16 *, 0x50) = 0x3E8;
    }
}
