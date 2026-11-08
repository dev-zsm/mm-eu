// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0162.h"

s32 func_800B5BE8(M2C_UNK, s32, M2C_UNK);           /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */

void ItemInbox_Idle(ItemInbox *this, PlayState *play) {
    if (func_800B5BE8(play, ((s16) M2C_FIELD(this, s16 *, 0x1C) >> 8) & 0x1F, play) != 0) {
        func_800B6490(this);
    }
}
