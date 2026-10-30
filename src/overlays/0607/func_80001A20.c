// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B02EC(s32, s32);                    /* extern */
M2C_UNK func_800E0FAC(s32, s32);                    /* extern */
M2C_UNK func_800E1F64(s32, s32);                    /* extern */

void func_80001A20(Actor *thisx, PlayState *play) {
    func_800E0FAC(play, (u8 *)thisx + 0x190);
    func_800E1F64(play, (u8 *)thisx + 0x1DC);
    func_800B02EC(play, M2C_FIELD(thisx, s32 *, 0x340));
}
