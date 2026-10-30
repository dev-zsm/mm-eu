// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_801A23EC(M2C_UNK, M2C_UNK);            /* extern */

void func_8000004C(Actor *thisx, PlayState *play) {
    if (M2C_FIELD(thisx, s16 *, 0x146) == 1) {
        func_801A23EC(0, 0);
    }
}
