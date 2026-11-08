// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0504.h"

M2C_UNK func_800F1944(s8, u8 *);                  /* extern */
s32 func_800F1984(s8, u8 *);                      /* extern */
M2C_UNK func_800F1A08(s8, u8 *);                  /* extern */
M2C_UNK func_80B5434C(u8 *);                      /* extern */

void BgKin2Picture_PlayCutscene(BgKin2Picture *this, PlayState *play) {
    if (func_800F1984(M2C_FIELD(this, s8 *, 0x38), this) != 0) {
        func_800F1A08(M2C_FIELD(this, s8 *, 0x38), this);
        M2C_FIELD(this, s8 *, 0x240) = 1;
        func_80B5434C(this);
        return;
    }
    func_800F1944(M2C_FIELD(this, s8 *, 0x38), this);
}
