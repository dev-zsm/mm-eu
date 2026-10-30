// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800BE404(s32 *, u8 *, u8 *, s16, f32, f32, f32, s32); /* extern */
M2C_UNK func_8012C73C(s32);                         /* extern */
M2C_UNK func_80133EDC(s32 *, s32, s32, M2C_UNK *, M2C_UNK *, u8 *); /* extern */
extern M2C_UNK D_80B57BB8;
extern M2C_UNK D_80B57D5C;

void func_8000292C(Actor *thisx, PlayState *play) {
    u8 temp_v0;

    M2C_FIELD(thisx, s32 *, 0x2DC) = 0;
    func_8012C73C(play->gfxCtx);
    func_80133EDC(play, M2C_FIELD(thisx, s32 *, 0x1E8), M2C_FIELD(thisx, s32 *, 0x204), &D_80B57BB8, &D_80B57D5C, thisx);
    if (M2C_FIELD(thisx, s16 *, 0x3F0) > 0) {
        func_800BE404(play, thisx, (u8 *)thisx + 0x234, M2C_FIELD(thisx, s16 *, 0x2DE), M2C_FIELD(thisx, f32 *, 0x2F0), 0.5f, M2C_FIELD(thisx, f32 *, 0x2EC), (s32) M2C_FIELD(thisx, u8 *, 0x403));
    }
    temp_v0 = M2C_FIELD(thisx, u8 *, 0x402);
    if ((temp_v0 & 0x40) && !(temp_v0 & 0x80)) {
        M2C_FIELD(thisx, u8 *, 0x402) = (u8) (temp_v0 | 0x80);
    }
}
