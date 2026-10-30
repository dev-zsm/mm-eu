// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800E0F5C(s32, s32, u8 *);            /* extern */
M2C_UNK func_800E10CC(s32, s32, u8 *, M2C_UNK *); /* extern */
extern M2C_UNK D_808B4A40;

void func_80000000(Actor *thisx, PlayState *play) {
    s32 sp1C;
    s32 temp_a1;

    temp_a1 = (u8 *)thisx + 0x144;
    sp1C = temp_a1;
    func_800E0F5C(play, temp_a1, thisx);
    func_800E10CC(play, temp_a1, thisx, &D_808B4A40);
    if (M2C_FIELD(thisx, s16 *, 0x1C) != 0) {
        M2C_FIELD(thisx, s32 *, 0x15C) = 0x40000;
    }
}
