// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_80137070(s32, s32);                    /* extern */

void func_8000016C(Actor *thisx, PlayState *play) {
    func_80137070((u8 *)thisx + 0x144, thisx);
}
