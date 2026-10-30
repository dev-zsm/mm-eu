// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800E0FAC(s32, u8 *, u8 *);         /* extern */

void func_800005A4(Actor *thisx, PlayState *play) {
    if (M2C_FIELD(thisx, s16 *, 0x1C) == 0) {
        func_800E0FAC(play, (u8 *)thisx + 0x144, thisx);
        func_800E0FAC(play, (u8 *)thisx + 0x190, thisx);
    }
}
