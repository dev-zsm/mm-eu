// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0184.h"

M2C_UNK func_800E0FAC(M2C_UNK, s32, M2C_UNK);       /* extern */
M2C_UNK func_80166800(u32);                         /* extern */
s32 func_8094DD98(u32);                             /* extern */
M2C_UNK func_8094DEF0(s32);                         /* extern */

void func_80000224(Actor *thisx, PlayState *play) {
    u32 temp_a0;

    func_800E0FAC(play, (u8 *)thisx + 0x188, play);
    temp_a0 = M2C_FIELD(thisx, s16 *, 0x1C) & 0xF;
    switch (temp_a0) {
    case 0:
        func_80166800(temp_a0);
        return;
    case 5:
    case 6:
    case 7:
    case 8:
        if (func_8094DD98(temp_a0) == 0) {
            func_8094DEF0(M2C_FIELD(thisx, s16 *, 0x1C) & 0xF);
        }
        /* fallthrough */
    default:
        return;
    }
}
