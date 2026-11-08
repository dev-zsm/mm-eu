// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0071.h"

f32 func_800C3F18(s32, s32, s32, M2C_UNK *, u8 *, s32); /* extern */

void func_800034D4(Actor *thisx, PlayState *play) {
    s32 pad;
    M2C_UNK sp28;

    M2C_FIELD(thisx, f32 *, 0x88) = func_800C3F18(play, (u8 *)play + 0x830, (u8 *)thisx + 0x80, &sp28, thisx, (u8 *)thisx + 0x24);
    M2C_FIELD(thisx, s8 *, 0xD0) = 0x32;
}
