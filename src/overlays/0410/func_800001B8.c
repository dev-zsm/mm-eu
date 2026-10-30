// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800CABA0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800CABC4(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_6001640;
extern M2C_UNK D_80AAFAB8;
extern M2C_UNK D_80AAFE70;

void func_800001B8(Actor *thisx, PlayState *play) {
    func_800FF8DC(thisx, &D_80AAFE70);
    func_800CABA0(thisx, 1);
    func_800CABC4(play, thisx, &D_6001640);
    M2C_FIELD(thisx, M2C_UNK **, 0x160) = &D_80AAFAB8;
}
