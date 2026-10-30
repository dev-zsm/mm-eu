// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800E0FAC(M2C_UNK, s32, s32, M2C_UNK);  /* extern */

void func_80002CD8(Actor *thisx, PlayState *play) {
    func_800E0FAC(play, (u8 *)thisx + 0x190, thisx, play);
}
