// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_80133EDC(s32, s32, s32, M2C_UNK, s32, u8 *); /* extern */

void func_80000198(Actor *thisx, PlayState *play) {
    func_80133EDC(play, M2C_FIELD(thisx, s32 *, 0x148), M2C_FIELD(thisx, s32 *, 0x164), 0, 0, thisx);
}
