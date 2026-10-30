// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800E1F64(M2C_UNK, s32, s32, M2C_UNK);  /* extern */

void func_800001FC(Actor *thisx, PlayState *play) {
    func_800E1F64(play, (u8 *)thisx + 0x3AC, thisx, play);
}
