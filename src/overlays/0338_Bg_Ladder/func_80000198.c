// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0338.h"

s32 func_800B5B20(M2C_UNK, s16, M2C_UNK);           /* extern */
M2C_UNK func_800F1944(s8);                          /* extern */
extern M2C_UNK D_80A32938;

void BgLadder_Wait(BgLadder *this, PlayState *play) {
    if (func_800B5B20(play, M2C_FIELD(this, s16 *, 0x162), play) != 0) {
        func_800F1944(M2C_FIELD(this, s8 *, 0x38));
        M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80A32938;
    }
}
