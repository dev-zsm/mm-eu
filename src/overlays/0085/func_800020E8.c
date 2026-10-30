// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

s32 func_800B5B20(s32, s32, u8 *);                /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
s8 func_8012F9A8(s32, M2C_UNK, u8 *);             /* extern */
extern M2C_UNK D_808A6198;

void func_800020E8(Actor *thisx, PlayState *play) {
    s32 temp_a1;

    M2C_FIELD(thisx, s8 *, 0x2C0) = func_8012F9A8((u8 *)play + 0x17D88, 1, thisx);
    temp_a1 = M2C_FIELD(thisx, s16 *, 0x1C) & 0x3F & 0xFF;
    if (((temp_a1 != 0x3F) && (func_800B5B20(play, temp_a1, thisx) != 0)) || (M2C_FIELD(thisx, s8 *, 0x2C0) < 0)) {
        func_800B6490(thisx);
        return;
    }
    M2C_FIELD(thisx, M2C_UNK **, 0x188) = &D_808A6198;
}
