// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_8018453C(u8 *, u8 *);              /* extern */

void func_80000100(Actor *thisx, PlayState *play) {
    if ((M2C_FIELD(thisx, s16 *, 0x1C) & 0xF) != 1) {
        func_8018453C((u8 *)thisx + 0x144, thisx);
    }
}
