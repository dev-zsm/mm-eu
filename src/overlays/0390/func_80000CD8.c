// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800E0FAC(s32, s32, u8 *);            /* extern */
M2C_UNK func_80112D7C(s32, M2C_UNK, u8 *);        /* extern */
extern M2C_UNK D_801E6EF0;

void func_80000CD8(Actor *thisx, PlayState *play) {
    func_800E0FAC(play, (u8 *)thisx + 0x320, thisx);
    if ((((s32) (M2C_FIELD(thisx, s16 *, 0x1C) & 0x780) >> 7) == 5) && (M2C_FIELD(thisx, u16 *, 0x3E4) & 0x2000)) {
        func_80112D7C(play, 0x61, thisx);
        M2C_FIELD(&D_801E6EF0, u8 *, 0x100E) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0x100E) & 0xEF);
    }
}
