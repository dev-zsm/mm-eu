// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_80AB01E4(s32);                         /* extern */
M2C_UNK func_80AB023C(s32);                         /* extern */

void func_80000170(Actor *thisx, PlayState *play) {
    func_80AB01E4(thisx);
    func_80AB023C(thisx);
}
