// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800E0FAC(s32, s32);                    /* extern */
M2C_UNK func_80137C80(s32, s32);                    /* extern */

void func_80001458(Actor *thisx, PlayState *play) {
    func_80137C80((u8 *)thisx + 0x190, play);
    func_800E0FAC(play, (u8 *)thisx + 0x144);
}
