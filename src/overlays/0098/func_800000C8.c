// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B5D20(s32, M2C_UNK);                /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
s32 func_800B877C(u8 *, s32);                     /* extern */
M2C_UNK func_800B87A0(u8 *, s32, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_808BC634(u8 *, s32);                 /* extern */

void func_800000C8(Actor *thisx, PlayState *play) {
    func_808BC634(thisx, play);
    if (!(M2C_FIELD(thisx, f32 *, 0x168) < 0.5f)) {
        if (func_800B877C(thisx, play) != 0) {
            func_800B5D20(play, 0x1F);
            func_800B6490(thisx);
            return;
        }
        func_800B87A0(thisx, play, 0xD, 0x41F00000, 80.0f);
    }
}
