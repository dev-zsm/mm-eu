// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_801017FC(u8 *, s16, s16, s16, s32, s32, u32, s32); /* extern */
M2C_UNK func_808B4F70(s32, s32);                    /* extern */

void func_80001028(Actor *thisx, PlayState *play) {
    f32 temp_f0;
    s32 temp_v0;

    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, s32), 0x1B8)(thisx, play);
    func_808B4F70(play, M2C_FIELD(thisx, s32 *, 0x1B4));
    temp_f0 = M2C_FIELD(thisx, f32 *, 0x1A4);
    temp_v0 = (u32) (temp_f0 * 255.0f) & 0xFF;
    func_801017FC((u8 *)thisx + 0x194, (s16) (s32) M2C_FIELD(thisx, f32 *, 0x24), (s16) (s32) M2C_FIELD(thisx, f32 *, 0x28), (s16) (s32) M2C_FIELD(thisx, f32 *, 0x2C), temp_v0, temp_v0, (u32) (temp_f0 * 100.0f), (s32) (temp_f0 * 800.0f));
}
