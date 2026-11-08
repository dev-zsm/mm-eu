// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0307.h"

M2C_UNK func_800C625C(s32, s32, s32, u8 *);       /* extern */
M2C_UNK func_801A818C(u8 *);                      /* extern */

void BgDblueMovebg_Destroy(Actor *thisx, PlayState *play) {
    s32 temp_v0;

    func_800C625C(play, (u8 *)play + 0x880, M2C_FIELD(thisx, s32 *, 0x144), thisx);
    temp_v0 = M2C_FIELD(thisx, s32 *, 0x160);
    if ((temp_v0 == 9) || (temp_v0 == 8)) {
        func_801A818C((u8 *)thisx + 0x1A8);
    }
}
