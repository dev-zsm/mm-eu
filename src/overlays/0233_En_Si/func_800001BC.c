// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0233.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_80971810();                            /* extern */

void EnSi_DraggedByHookshot(EnSi *this) {
    if ((M2C_FIELD(this, s32 *, 4) & 0x2000) != 0x2000) {
        func_80971810();
        func_800B6490(this);
    }
}
