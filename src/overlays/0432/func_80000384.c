// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0432.h"

M2C_UNK func_800E26E8(s32, s32, u8 *, u8 *);    /* extern */

void func_80000384(Actor *thisx, PlayState *play) {
    M2C_FIELD(thisx, s16 *, 0x222) = (s16) (s32) M2C_FIELD(thisx, f32 *, 0x24);
    M2C_FIELD(thisx, s16 *, 0x224) = (s16) (s32) M2C_FIELD(thisx, f32 *, 0x28);
    M2C_FIELD(thisx, s16 *, 0x226) = (s16) (s32) M2C_FIELD(thisx, f32 *, 0x2C);
    func_800E26E8(play, (u8 *)play + 0x18884, (u8 *)thisx + 0x1DC, thisx);
}
