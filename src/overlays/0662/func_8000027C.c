// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

s32 func_800B5B20(M2C_UNK, s32, u8 *, M2C_UNK);   /* extern */
M2C_UNK func_80C0A3E0(u8 *);                      /* extern */
M2C_UNK func_80C0A520(u8 *);                      /* extern */

void func_8000027C(Actor *thisx, PlayState *play) {
    if (func_800B5B20(play, M2C_FIELD(thisx, s16 *, 0x1C) & 0x7F, thisx, play) != 0) {
        func_80C0A520(thisx);
        return;
    }
    func_80C0A3E0(thisx);
}
