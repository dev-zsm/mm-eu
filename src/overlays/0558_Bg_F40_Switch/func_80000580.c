// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0558.h"

extern M2C_UNK D_80BA9A08;

void BgF40Switch_IdleUnpressed(BgF40Switch *this, PlayState *play) {
    if (M2C_FIELD(this, s8 *, 0x15E) != 0) {
        M2C_FIELD(this, M2C_UNK **, 0x164) = &D_80BA9A08;
    }
}
