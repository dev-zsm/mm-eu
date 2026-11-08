// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0436.h"

M2C_UNK func_800B6308(s32, M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_80AD0C90;
extern s32 D_80AD0C94;

void func_80000000(Actor *thisx, PlayState *play) {
    if (D_80AD0C94 == 0) {
        func_800B6308(play, 0x1D2, &D_80AD0C90, 2);
        D_80AD0C94 = 1;
    }
    M2C_FIELD(thisx, M2C_UNK **, 0x1EC) = &D_80AD0C90;
}
