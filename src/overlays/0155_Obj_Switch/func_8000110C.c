// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0155.h"

s32 func_800B5B20(M2C_UNK, s32, u8 *, M2C_UNK);   /* extern */
M2C_UNK func_80920824(u8 *);                      /* extern */
M2C_UNK func_80920900(u8 *);                      /* extern */

void ObjSwitch_EyeSwitchUnfrozen(ObjSwitch *this, PlayState *play) {
    if (func_800B5B20(play, ((s16) M2C_FIELD(this, s16 *, 0x1C) >> 8) & 0x7F, this, play) != 0) {
        func_80920900(this);
        return;
    }
    func_80920824(this);
}
