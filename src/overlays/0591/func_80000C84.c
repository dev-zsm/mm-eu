// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_801342C8(s32, s32, s32, u8, s32, s32, u8 *); /* extern */
M2C_UNK func_80181D88(s16, M2C_UNK);                /* extern */

void func_80000C84(Actor *thisx, PlayState *play) {
    if (M2C_FIELD(thisx, f32 *, 0x160) < 1400.0f) {
        func_80181D88(M2C_FIELD(thisx, s16 *, 0x15A), 1);
        func_801342C8(play, M2C_FIELD(thisx, s32 *, 0x168), M2C_FIELD(thisx, s32 *, 0x184), M2C_FIELD(thisx, u8 *, 0x166), 0, 0, thisx);
    }
}
