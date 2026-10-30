// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800C9F78(s32, s32, s32, s32, u8 *, M2C_UNK *); /* extern */

void func_800004FC(Actor *thisx, PlayState *play) {
    s32 pad[2];
    M2C_UNK sp2C;

    func_800C9F78(play, (u8 *)play + 0x830, M2C_FIELD(thisx, s32 *, 0x24), M2C_FIELD(thisx, s32 *, 0x2C), (u8 *)thisx + 0x160, &sp2C);
    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, s32), 0x15C)(thisx, play);
}
