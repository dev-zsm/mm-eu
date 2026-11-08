// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0080.h"

s16 func_8089EFDC();                                /* extern */
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_8089FB08;

void EnBubble_Disappear(EnBubble *this, PlayState *play) {
    s16 temp_v0;

    temp_v0 = func_8089EFDC();
    if (temp_v0 >= 0) {
        M2C_FIELD(this, M2C_UNK **, 0xC8) = &D_800B3F30;
        M2C_FIELD(this, s16 *, 0x202) = temp_v0;
        M2C_FIELD(this, M2C_UNK **, 0x144) = &D_8089FB08;
    }
}
