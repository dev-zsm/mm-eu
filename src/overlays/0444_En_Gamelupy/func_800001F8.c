// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0444.h"

s32 func_800B6404(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_80ADB6C4(u8 *);                      /* extern */

void EnGamelupy_FindSharedMemory(EnGamelupy *this, PlayState *play) {
    s32 temp_v0;

    temp_v0 = func_800B6404(play, 0x1D2, play);
    if (temp_v0 != 0) {
        M2C_FIELD(this, s32 *, 0x198) = temp_v0;
        func_80ADB6C4(this);
    }
}
