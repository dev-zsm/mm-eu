// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_8012CA60(s32);                         /* extern */
M2C_UNK func_80133EDC(s32 *, s32, s32, M2C_UNK *, s32, u8 *); /* extern */
extern M2C_UNK D_8089E388;

void func_800003DC(Actor *thisx, PlayState *play) {
    func_8012CA60(play->gfxCtx);
    func_80133EDC(play, M2C_FIELD(thisx, s32 *, 0x160), M2C_FIELD(thisx, s32 *, 0x17C), &D_8089E388, 0, thisx);
}
