// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0139.h"

M2C_UNK func_800B6490();                            /* extern */

void ArrowFire_Update(Actor *thisx, PlayState *play) {
    u8 temp_v0;

    temp_v0 = M2C_FIELD(play, u8 *, 0x1682E);
    if ((temp_v0 == 0xE) || (temp_v0 == 0x12)) {
        func_800B6490();
        return;
    }
    M2C_FIELD(thisx, M2C_UNK (**)(), 0x258)();
}
