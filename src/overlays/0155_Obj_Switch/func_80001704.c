// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0155.h"

s32 func_800CAD6C(u8 *);                          /* extern */
M2C_UNK func_8091F90C(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_8091FA0C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80920138(u8 *, s32, M2C_UNK (*)(u8 *), M2C_UNK); /* extern */
M2C_UNK func_80920EB8(u8 *);                      /* extern */

void ObjSwitch_LargeFloorSwitchUp(ObjSwitch *this, PlayState *play) {
    s32 temp_v0;

    temp_v0 = ((s16) M2C_FIELD(this, s16 *, 0x1C) >> 4) & 7;
    if (temp_v0 == 0) {
        if (func_800CAD6C(this) != 0) {
            func_8091FA0C(this, 1);
            func_80920138(this, play, func_80920EB8, 1);
        }
    } else if (temp_v0 == 2) {
        if (func_800CAD6C(this) != 0) {
            func_8091FA0C(this, 1);
            func_80920138(this, play, func_80920EB8, 1);
        }
    } else if ((temp_v0 == 3) && (func_800CAD6C(this) != 0)) {
        func_8091FA0C(this, 2);
        func_8091F90C(this, play, 0);
        func_80920EB8(this);
    }
}
