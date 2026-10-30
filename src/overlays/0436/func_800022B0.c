// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_8012C73C(s32);                         /* extern */
M2C_UNK func_801342C8(s32 *, s32, s32, u8, M2C_UNK *, M2C_UNK *, u8 *); /* extern */
extern M2C_UNK D_80AD0948;
extern M2C_UNK D_80AD09C0;

void func_800022B0(Actor *thisx, PlayState *play) {
    func_8012C73C(play->gfxCtx);
    func_801342C8(play, M2C_FIELD(thisx, s32 *, 0x194), M2C_FIELD(thisx, s32 *, 0x1B0), M2C_FIELD(thisx, u8 *, 0x192), &D_80AD0948, &D_80AD09C0, thisx);
}
