// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80A1D05C(u8 *, s32);                 /* extern */
M2C_UNK func_80A1D1B8(u8 *);                      /* extern */

void func_80000444(Actor *thisx, PlayState *play) {
    func_80A1D1B8(thisx);
    func_80137070((u8 *)thisx + 0x144);
    func_80A1D05C(thisx, play);
    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, s32), 0x260)(thisx, play);
}
