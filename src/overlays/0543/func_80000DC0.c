// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0543.h"

u8 *func_8013D9F8(s32, s16, M2C_UNK);             /* extern */

void func_80000DC0(Actor *thisx, PlayState *play) {
    u8 *temp_v0;

    temp_v0 = func_8013D9F8(play, (s16) ((s32) (M2C_FIELD(thisx, s16 *, 0x1C) & 0x7E00) >> 9), 0x3F);
    M2C_FIELD(thisx, u8 **, 0x1EC) = temp_v0;
    M2C_FIELD(thisx, u8 **, 0x1F0) = func_8013D9F8(play, (s16) M2C_FIELD(temp_v0, u8 *, 1), 0x3F);
}
