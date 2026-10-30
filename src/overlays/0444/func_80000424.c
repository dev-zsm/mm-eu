// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800B763C(s32, u8 *, M2C_UNK, M2C_UNK, f32, s32); /* extern */
M2C_UNK func_80ADB870(u8 *, s32);                 /* extern */

void func_80000424(Actor *thisx, PlayState *play) {
    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, s32), 0x190)(thisx, play);
    func_800B680C(thisx);
    func_800B763C(play, thisx, 0x42000000, 0x41F00000, 0.0f, 0xC);
    func_80ADB870(thisx, play);
}
