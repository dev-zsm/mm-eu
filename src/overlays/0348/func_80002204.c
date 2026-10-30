// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B7DD4(u8 *, s32 *, M2C_UNK);      /* extern */
M2C_UNK func_8012C73C(s32);                         /* extern */
M2C_UNK func_8012CE24(s32);                         /* extern */
M2C_UNK func_801342C8(s32 *, s32, s32, u8, M2C_UNK *, M2C_UNK *, u8 *); /* extern */
extern M2C_UNK D_80A3CC70;
extern M2C_UNK D_80A3CCAC;

void func_80002204(Actor *thisx, PlayState *play) {
    func_8012C73C(play->gfxCtx);
    func_8012CE24(play->gfxCtx);
    func_800B7DD4(thisx, play, 0);
    func_801342C8(play, M2C_FIELD(thisx, s32 *, 0x148), M2C_FIELD(thisx, s32 *, 0x164), M2C_FIELD(thisx, u8 *, 0x146), &D_80A3CC70, &D_80A3CCAC, thisx);
}
