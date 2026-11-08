// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0507.h"

f32 func_8008704C();                                /* extern */
M2C_UNK func_800B372C(u8 *, s32, s32, s32, s32);  /* extern */

void func_800016EC(Actor *thisx, PlayState *play) {
    s16 temp_v0;

    temp_v0 = (s16) (s32) ((func_8008704C() * 20.0f) + 30.0f);
    if (!(M2C_FIELD(play, s32 *, 0x9C) & 7)) {
        func_800B372C(play, (u8 *)thisx + 0x3A4, (u8 *)thisx + 0x3B0, (u8 *)thisx + 0x3BC, (s32) temp_v0);
    }
}
