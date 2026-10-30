// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_80BFA214(u8 *, s32);                 /* extern */
M2C_UNK func_80BFA464(u8 *, s32);                 /* extern */
M2C_UNK func_80BFA4B8(u8 *, s32);                 /* extern */

void func_800004E4(Actor *thisx, PlayState *play) {
    func_80BFA4B8(thisx, play);
    func_80BFA214(thisx, play);
    func_80BFA464(thisx, play);
    M2C_FIELD(thisx, s16 *, 0x1AE) = (s16) (M2C_FIELD(thisx, s16 *, 0x1AE) + 1);
}
