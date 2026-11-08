// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0373.h"

M2C_UNK func_8019FF78(M2C_UNK);                     /* extern */

void EnTest6_SetupInvertedSoTCutscene(EnTest6 *this, PlayState *play) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(this, s16 *, 0x1C);
    M2C_FIELD(this, s16 *, 0x274) = 0x5A;
    M2C_FIELD(this, s16 *, 0x27A) = 0x64;
    M2C_FIELD(this, s16 *, 0x286) = 0;
    if (temp_v0 == 0x19) {
        func_8019FF78(0x485D);
        return;
    }
    if (temp_v0 == 0x18) {
        func_8019FF78(0x485E);
    }
}
