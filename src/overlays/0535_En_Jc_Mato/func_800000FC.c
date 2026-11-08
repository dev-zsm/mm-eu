// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0535.h"

M2C_UNK func_800B6490();                            /* extern */

void EnJcMato_Idle(EnJcMato *this, PlayState *play) {
    s16 temp_v0;
    s16 var_v1;

    if (M2C_FIELD(this, s16 *, 0x1A2) != 0) {
        temp_v0 = M2C_FIELD(this, s16 *, 0x1A0);
        if (temp_v0 == 0) {
            var_v1 = 0;
        } else {
            M2C_FIELD(this, s16 *, 0x1A0) = (s16) (temp_v0 - 1);
            var_v1 = M2C_FIELD(this, s16 *, 0x1A0);
        }
        if (var_v1 == 0) {
            func_800B6490();
        }
    }
}
