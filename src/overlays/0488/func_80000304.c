// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_80102484(s32, s32, s32, s32);          /* extern */

void func_80000304(Actor *thisx, PlayState *play) {
    func_80102484(play, (u8 *)play + 0x818, M2C_FIELD(thisx, s32 *, 0x2FC), play);
}
