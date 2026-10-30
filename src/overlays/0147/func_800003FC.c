// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

s32 func_800B5B20(M2C_UNK, s32);                    /* extern */
M2C_UNK func_800B5B64(M2C_UNK, s32);                /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
s32 func_800B8254(u8 *, M2C_UNK);                 /* extern */
s32 func_80912A8C(u8 *, M2C_UNK);                 /* extern */

void func_800003FC(Actor *thisx, PlayState *play) {
    s16 temp_v0;
    s32 temp_a1;

    if (func_80912A8C(thisx, play) == 0) {
        if (func_800B8254(thisx, play) != 0) {
            temp_a1 = (s32) (M2C_FIELD(thisx, s16 *, 0x1C) & 0x7F00) >> 8;
            if (temp_a1 != 0x7F) {
                func_800B5B64(play, temp_a1);
            }
            func_800B6490(thisx);
            return;
        }
        temp_v0 = M2C_FIELD(thisx, s16 *, 0x16);
        if ((temp_v0 >= 0) || (temp_v0 < -0x80) || (func_800B5B20(play, -1 - temp_v0) != 0)) {
            M2C_FIELD(thisx, M2C_UNK (**)(u8 *, M2C_UNK), 0x144)(thisx, play);
        }
    }
}
