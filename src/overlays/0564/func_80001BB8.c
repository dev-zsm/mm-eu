// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B64E0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800B8D94(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80BAFC18(u8 *, s32);                 /* extern */

void func_80001BB8(Actor *thisx, PlayState *play) {
    func_800B64E0(thisx, 0x42700000);
    func_80137070((u8 *)thisx + 0x144);
    func_800B680C(thisx);
    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, s32), 0x2D8)(thisx, play);
    if (M2C_FIELD(thisx, u16 *, 0x328) & 8) {
        func_800B8D94(thisx, 0x3285);
    }
    func_80BAFC18(thisx, play);
}
