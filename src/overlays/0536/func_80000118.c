// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800E0FAC(s32, s32);                    /* extern */
M2C_UNK func_800E1C28(s32, s32);                    /* extern */

void func_80000118(Actor *thisx, PlayState *play) {
    func_800E1C28(play, (u8 *)thisx + 0x144);
    func_800E0FAC(play, (u8 *)thisx + 0x1C4);
}
