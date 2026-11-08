// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0448.h"

M2C_UNK func_80AE1690();                            /* extern */
extern M2C_UNK D_80AE18C4;

void EnGakufu_WaitForTimer(EnGakufu *this, PlayState *play) {
    if (M2C_FIELD(this, s16 *, 0x14) > 0) {
        func_80AE1690();
        M2C_FIELD(this, M2C_UNK **, 0x150) = &D_80AE18C4;
    }
}
