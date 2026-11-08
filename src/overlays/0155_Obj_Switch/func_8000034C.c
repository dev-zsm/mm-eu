// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0155.h"

s32 func_800CAD00(u8 *);                          /* extern */

void ObjSwitch_SetFloorSwitchSnapPlayerState(ObjSwitch *this, s32 state) {
    if (func_800CAD00(this) != 0) {
        M2C_FIELD(this, s8 *, 0x170) = (s8) state;
    }
}
