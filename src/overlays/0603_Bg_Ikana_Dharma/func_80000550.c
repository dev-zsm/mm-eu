// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0603.h"

M2C_UNK func_800F1944(s8, u8 *);                  /* extern */
s32 func_800F1984(s8, u8 *);                      /* extern */
M2C_UNK func_800F1A08(s8, u8 *);                  /* extern */
M2C_UNK func_80BD158C(u8 *);                      /* extern */

void BgIkanaDharma_StartCutscene(BgIkanaDharma *this, PlayState *play) {
    if (func_800F1984(M2C_FIELD(this, s8 *, 0x38), this) != 0) {
        func_800F1A08(M2C_FIELD(this, s8 *, 0x38), this);
        func_80BD158C(this);
        return;
    }
    func_800F1944(M2C_FIELD(this, s8 *, 0x38), this);
}
