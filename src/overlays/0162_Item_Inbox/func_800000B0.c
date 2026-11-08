// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0162.h"

M2C_UNK func_800B7DD4(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_800B7E9C(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_800EE0C0(s32, s16);                    /* extern */

void ItemInbox_Draw(Actor *thisx, PlayState *play) {
    func_800B7DD4(thisx, play, 0);
    func_800B7E9C(thisx, play, 0);
    func_800EE0C0(play, (s16) (M2C_FIELD(thisx, s16 *, 0x1C) & 0xFF));
}
