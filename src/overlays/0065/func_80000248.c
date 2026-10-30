// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800E09D8(u8 *, s32);                 /* extern */
M2C_UNK func_800E0FAC(u8 *, s32);                 /* extern */

void func_80000248(Actor *thisx, PlayState *play) {
    func_800E09D8(play, (u8 *)thisx + 0x190);
    func_800E0FAC(play, (u8 *)thisx + 0x144);
    if (M2C_FIELD(thisx, u8 *, 0x1F9) != 0) {
        M2C_FIELD(play, u8 *, 0x1CA5) = (u8) (M2C_FIELD(play, u8 *, 0x1CA5) & 0xFFFE);
    }
}
