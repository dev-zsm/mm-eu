// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_80A18830(s32, s32);                    /* extern */
M2C_UNK func_80A188E4(s32, s32);                    /* extern */

void func_80000A38(Actor *thisx, PlayState *play) {
    func_80A18830(thisx, play);
    func_80A188E4(thisx, play);
}
