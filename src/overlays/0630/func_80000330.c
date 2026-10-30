// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800CABA0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800CABC4(s32, u8 *, M2C_UNK *);      /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
s32 func_80100304(M2C_UNK *);                       /* extern */
M2C_UNK func_80BEFA14(u8 *);                      /* extern */
extern M2C_UNK D_600C670;
extern M2C_UNK D_600CBAC;
extern M2C_UNK D_80BEFEA0;

void func_80000330(Actor *thisx, PlayState *play) {
    func_800FF8DC(thisx, &D_80BEFEA0);
    func_800CABA0(thisx, 1);
    func_800CABC4(play, thisx, &D_600CBAC);
    M2C_FIELD(thisx, s32 *, 0x15C) = func_80100304(&D_600C670);
    func_80BEFA14(thisx);
}
