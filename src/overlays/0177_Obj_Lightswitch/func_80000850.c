// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0177.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800B8D94(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_809447DC();                            /* extern */

void ObjLightSwitch_Fade(ObjLightswitch *this) {
    M2C_FIELD(this, s16 *, 0x1AE) = (s16) (M2C_FIELD(this, s16 *, 0x1AE) - 0xC8);
    func_809447DC();
    if (M2C_FIELD(this, s16 *, 0x1AE) < 0) {
        func_800B6490(this);
        return;
    }
    func_800B8D94(this, 0x321F);
}
