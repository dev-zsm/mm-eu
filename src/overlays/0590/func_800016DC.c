// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_8012C73C(s32);                         /* extern */
M2C_UNK func_801342C8(s32 *, s32, s32, u8, s32, s32, u8 *); /* extern */

void func_800016DC(Actor *thisx, PlayState *play) {
    func_8012C73C(play->gfxCtx);
    func_801342C8(play, M2C_FIELD(thisx, s32 *, 0x198), M2C_FIELD(thisx, s32 *, 0x1B4), M2C_FIELD(thisx, u8 *, 0x196), 0, 0, thisx);
}
