// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
s32 func_80100304(M2C_UNK *);                       /* extern */
extern M2C_UNK D_6002CE0;
extern M2C_UNK D_80AB00E0;

void func_80000000(Actor *thisx, PlayState *play) {
    func_800FF8DC(thisx, &D_80AB00E0);
    M2C_FIELD(thisx, s32 *, 0x144) = func_80100304(&D_6002CE0);
}
