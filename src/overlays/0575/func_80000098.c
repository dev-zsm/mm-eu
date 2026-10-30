// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

s32 func_800B5C34(s32, s8);                         /* extern */
M2C_UNK func_800CABA0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800CABC4(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
s32 func_80BBA430(u8 *, s32);                     /* extern */
M2C_UNK func_80BBA5C8(u8 *);                      /* extern */
M2C_UNK func_80BBA73C(u8 *);                      /* extern */
M2C_UNK func_80BBA888(u8 *);                      /* extern */
M2C_UNK func_80BBAA04(u8 *);                      /* extern */
extern M2C_UNK D_6000F28;
extern M2C_UNK D_80BBAAB0;

void func_80000098(Actor *thisx, PlayState *play) {
    func_800FF8DC(thisx, &D_80BBAAB0);
    func_800CABA0(thisx, 0);
    func_800CABC4(play, thisx, &D_6000F28);
    if (!(((s16) M2C_FIELD(thisx, s16 *, 0x1C) >> 8) & 1)) {
        if (func_80BBA430(thisx, play) != 0) {
            func_80BBA73C(thisx);
            return;
        }
        func_80BBA5C8(thisx);
        return;
    }
    if (func_800B5C34(play, M2C_FIELD(thisx, s8 *, 3)) != 0) {
        func_80BBAA04(thisx);
        return;
    }
    func_80BBA888(thisx);
}
