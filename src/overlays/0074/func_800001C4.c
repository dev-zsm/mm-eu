// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800E0FAC(s32, s32);                    /* extern */
M2C_UNK func_800E1574(s32, s32);                    /* extern */
M2C_UNK func_800E1F64(s32, s32);                    /* extern */

void func_800001C4(Actor *thisx, PlayState *play) {
    u8 *temp_v0;

    func_800E0FAC(play, (u8 *)thisx + 0x3C4);
    func_800E1F64(play, (u8 *)thisx + 0x410);
    func_800E1574(play, (u8 *)thisx + 0x468);
    if (M2C_FIELD(thisx, s16 *, 0x1C) != 0) {
        temp_v0 = M2C_FIELD(thisx, u8 **, 0x120);
        if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, s32 *, 0x138) != 0)) {
            M2C_FIELD(temp_v0, u8 *, 0x2AC) = (u8) (M2C_FIELD(temp_v0, u8 *, 0x2AC) - 1);
        }
    }
}
