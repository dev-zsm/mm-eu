// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0280.h"

M2C_UNK func_800B8364(u8 *, s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800B861C(s32, u8 *, s16 *, s16 *);   /* extern */

s32 func_80000210(Actor *thisx, PlayState *play) {
    s16 sp1E;
    s16 sp1C;

    func_800B861C(play, thisx, &sp1E, &sp1C);
    if ((M2C_FIELD(thisx, u8 *, 0x1E2) == 0) && ((sp1E >= 0) || (sp1E < 0x140)) && ((sp1C >= 0) || (sp1C < 0xF0))) {
        func_800B8364(thisx, play, 0x41F00000, 0x2E);
    }
    return 1;
}
