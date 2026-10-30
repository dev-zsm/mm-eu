// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

s32 func_800B5B20(M2C_UNK, s32, u8 *, M2C_UNK);   /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
extern u8 *D_801EB7E0;

void func_8000006C(Actor *thisx, PlayState *play) {
    s16 temp_v0;

    if (func_800B5B20(play, M2C_FIELD(thisx, s16 *, 0x1C) & 0x7F, thisx, play) != 0) {
        func_800B6490(thisx);
        return;
    }
    temp_v0 = M2C_FIELD(D_801EB7E0, s16 *, 0x70E);
    if (M2C_FIELD(thisx, f32 *, 0x94) < (f32) (temp_v0 * temp_v0)) {
        M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) & 0xBFFFFFFF);
        return;
    }
    M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) | 0x40000000);
}
