// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0256.h"

M2C_UNK func_8098A6A0(s32, s32);                    /* extern */
M2C_UNK func_8098A77C(s32, s32);                    /* extern */

void func_80000D50(Actor *thisx, PlayState *play) {
    func_8098A6A0(thisx, play);
    func_8098A77C(thisx, play);
}
