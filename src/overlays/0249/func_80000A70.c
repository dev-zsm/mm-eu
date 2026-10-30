// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_80985560(u8 *, s32);                 /* extern */
M2C_UNK func_809855E4(u8 *, s32);                 /* extern */

void func_80000A70(Actor *thisx, PlayState *play) {
    func_80985560(thisx, play);
    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, s32), 0x31C)(thisx, play);
    func_809855E4(thisx, play);
}
