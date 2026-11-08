// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0127.h"

M2C_UNK func_800E26E8(s32, s32, u8 *, u8 *);    /* extern */

void func_800001F0(Actor *thisx, PlayState *play) {
    M2C_FIELD(thisx, s16 *, 0x232) = (s16) (s32) M2C_FIELD(thisx, f32 *, 0x24);
    M2C_FIELD(thisx, s16 *, 0x234) = (s16) (s32) M2C_FIELD(thisx, f32 *, 0x28);
    M2C_FIELD(thisx, s16 *, 0x236) = (s16) (s32) M2C_FIELD(thisx, f32 *, 0x2C);
    if (M2C_FIELD(thisx, u8 *, 0x23D) == 0) {
        func_800E26E8(play, (u8 *)play + 0x18884, (u8 *)thisx + 0x1EC, thisx);
    }
}
