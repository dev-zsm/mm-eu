// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0080.h"

M2C_UNK func_800B6490(s32);                         /* extern */
M2C_UNK func_800F0308(s32, s32, M2C_UNK, M2C_UNK);  /* extern */
s32 func_8089ED80(s32, s32);                        /* extern */

void EnBubble_Pop(EnBubble *this, PlayState *play) {
    if (func_8089ED80(this, play) >= 0) {
        func_800F0308(play, (u8 *)this + 0x24, 0x3C, 0x3949);
        func_800B6490(this);
    }
}
