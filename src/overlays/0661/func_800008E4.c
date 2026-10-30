// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B763C(s32, u8 *, M2C_UNK, M2C_UNK, f32, s32); /* extern */
M2C_UNK func_80C09100(u8 *, s32);                 /* extern */
M2C_UNK func_80C092A4(u8 *);                      /* extern */
M2C_UNK func_80C0952C(u8 *, s32);                 /* extern */

void func_800008E4(Actor *thisx, PlayState *play) {
    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, s32), 0x188)(thisx, play);
    func_80C0952C(thisx, play);
    if (M2C_FIELD(thisx, s32 *, 0x13C) != 0) {
        func_80C09100(thisx, play);
        func_80C092A4(thisx);
    }
    func_800B763C(play, thisx, 0x41F00000, 0x41400000, 0.0f, 4);
}
