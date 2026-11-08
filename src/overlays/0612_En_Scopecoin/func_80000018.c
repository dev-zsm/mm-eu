// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0612.h"

M2C_UNK func_800A7C50(s32, u8 *, M2C_UNK);        /* extern */
s32 func_800B5CDC(s32, s32);                        /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */

void EnScopecoin_CheckCollectible(EnScopecoin *this, PlayState *play) {
    if (func_800B5CDC(play, (s32) (M2C_FIELD(this, s16 *, 0x1C) & 0x7F0) >> 4) != 0) {
        func_800A7C50(play, (u8 *)this + 0x24, 2);
        func_800B6490(this);
    }
}
