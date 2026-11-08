// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0351.h"

s32 func_800B7164(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_800B8B1C(s32, u8 *, M2C_UNK, s16, f32); /* extern */

void func_80000280(BgSpoutFire *this, PlayState *play) {
    s16 var_a3;

    if (func_800B7164(this, 0x4000) != 0) {
        var_a3 = M2C_FIELD(this, s16 *, 0xBE);
    } else {
        var_a3 = M2C_FIELD(this, s16 *, 0xBE) + 0x8000;
    }
    func_800B8B1C(play, this, 0x40A00000, var_a3, 1.0f);
}
