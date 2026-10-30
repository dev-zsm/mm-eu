// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_80102484(s32, s32, s32, u8 *);       /* extern */

void func_8000022C(Actor *thisx, PlayState *play) {
    if (!(M2C_FIELD(thisx, s16 *, 0x1C) & 0x4000)) {
        func_80102484(play, (u8 *)play + 0x818, M2C_FIELD(thisx, s32 *, 0x148), thisx);
    }
}
