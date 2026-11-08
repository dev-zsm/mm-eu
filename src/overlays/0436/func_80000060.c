// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0436.h"

M2C_UNK func_800B638C(M2C_UNK, M2C_UNK);            /* extern */
extern s16 D_80AD0C98;

void func_80000060(Actor *thisx, PlayState *play) {
    if (D_80AD0C98 == 0) {
        func_800B638C(play, 0x1D2);
        D_80AD0C98 = 1;
    }
}
