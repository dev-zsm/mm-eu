// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80BF9AB4(u8 *, s32);                 /* extern */
M2C_UNK func_80BF9AF8(u8 *, s32);                 /* extern */

void func_800014D8(Actor *thisx, PlayState *play) {
    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, s32), 0x1D4)(thisx, play);
    func_80137070((u8 *)thisx + 0x190);
    func_80BF9AB4(thisx, play);
    func_80BF9AF8(thisx, play);
}
