// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
s32 func_80100304(M2C_UNK *);                       /* extern */
extern M2C_UNK D_60012E8;
extern s32 D_801E6F00;
extern M2C_UNK D_80BFB1C0;
extern s32 D_80BFB210;

void func_80000000(Actor *thisx, PlayState *play) {
    func_800FF8DC(thisx, &D_80BFB1C0);
    D_80BFB210 = func_80100304(&D_60012E8);
    M2C_FIELD(thisx, s8 *, 0x144) = (s8) D_801E6F00;
}
