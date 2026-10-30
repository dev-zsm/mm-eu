// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_80A8ABEC(u8 *, s32);                 /* extern */
M2C_UNK func_80A8B02C(u8 *, s32);                 /* extern */

void func_80001494(Actor *thisx, PlayState *play) {
    func_80137070((u8 *)thisx + 0x144);
    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, s32), 0x23C)(thisx, play);
    M2C_FIELD(thisx, u16 *, 0x262) = (u16) (M2C_FIELD(thisx, u16 *, 0x262) + 1);
    func_80A8ABEC(thisx, play);
    func_80A8B02C(thisx, play);
}
