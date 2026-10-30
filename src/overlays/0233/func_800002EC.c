// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B7DD4(s32, s32, M2C_UNK);           /* extern */
M2C_UNK func_800B7E9C(s32, s32, M2C_UNK);           /* extern */
M2C_UNK func_800EE0C0(s32, M2C_UNK);                /* extern */

void func_800002EC(Actor *thisx, PlayState *play) {
    func_800B7E9C(thisx, play, 0);
    func_800B7DD4(thisx, play, 0);
    func_800EE0C0(play, 0x56);
}
