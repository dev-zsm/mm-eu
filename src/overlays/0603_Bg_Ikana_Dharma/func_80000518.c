// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0603.h"

M2C_UNK func_800F1944(s8);                          /* extern */
extern M2C_UNK D_80BD1530;

void BgIkanaDharma_SetupStartCutscene(BgIkanaDharma *this) {
    func_800F1944(M2C_FIELD(this, s8 *, 0x38));
    M2C_FIELD(this, M2C_UNK **, 0x1A8) = &D_80BD1530;
}
