// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0155.h"

M2C_UNK func_8091F978();                            /* extern */
M2C_UNK func_8091F9B4(u8 *);                      /* extern */
M2C_UNK func_80920900(u8 *);                      /* extern */

void ObjSwitch_EyeSwitchClosing(ObjSwitch *this, PlayState *play) {
    M2C_FIELD(this, s8 *, 0x164) = (s8) (M2C_FIELD(this, s8 *, 0x164) + 1);
    if (M2C_FIELD(this, s8 *, 0x164) >= 3) {
        func_8091F978();
        func_8091F9B4(this);
        func_80920900(this);
    }
}
