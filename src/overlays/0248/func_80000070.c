// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

s32 func_800B5B20(s32, s32);                        /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
s32 func_80984780(u8 *, s32);                     /* extern */
extern M2C_UNK D_80984B70;

void func_80000070(Actor *thisx, PlayState *play) {
    func_800FF8DC(thisx, &D_80984B70);
    if (func_80984780(thisx, play) == 0) {
        M2C_FIELD(thisx, s8 *, 0x144) = -1;
    }
    if (func_800B5B20(play, M2C_FIELD(thisx, s16 *, 0x1C) & 0x7F) != 0) {
        func_800B6490(thisx);
    }
}
