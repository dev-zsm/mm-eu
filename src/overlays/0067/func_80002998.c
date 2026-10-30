// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800BE404(s32 *, u8 *, u8 *, M2C_UNK, f32, f32, f32, s32); /* extern */
M2C_UNK func_8012C73C(s32);                         /* extern */
M2C_UNK func_80133EDC(s32 *, s32, s32, M2C_UNK *, M2C_UNK *, u8 *); /* extern */
extern M2C_UNK D_80878564;
extern M2C_UNK D_808785D4;

void func_80002998(Actor *thisx, PlayState *play) {
    f32 temp_f0;

    func_8012C73C(play->gfxCtx);
    func_80133EDC(play, M2C_FIELD(thisx, s32 *, 0x148), M2C_FIELD(thisx, s32 *, 0x164), &D_80878564, &D_808785D4, thisx);
    temp_f0 = M2C_FIELD(thisx, f32 *, 0x334);
    func_800BE404(play, thisx, (u8 *)thisx + 0x348, 9, M2C_FIELD(thisx, f32 *, 0x340) * temp_f0, M2C_FIELD(thisx, f32 *, 0x344) * temp_f0, M2C_FIELD(thisx, f32 *, 0x33C), (s32) M2C_FIELD(thisx, u8 *, 0x300));
}
