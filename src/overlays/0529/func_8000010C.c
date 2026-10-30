// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800C625C(s32, s32, s32, u8 *);       /* extern */
M2C_UNK func_800E0FAC(s32, u8 *);                 /* extern */

void func_8000010C(Actor *thisx, PlayState *play) {
    if (!(M2C_FIELD(thisx, s16 *, 0x1C) & 0x8000)) {
        func_800C625C(play, (u8 *)play + 0x880, M2C_FIELD(thisx, s32 *, 0x144), thisx);
    }
    func_800E0FAC(play, (u8 *)thisx + 0x15C);
}
