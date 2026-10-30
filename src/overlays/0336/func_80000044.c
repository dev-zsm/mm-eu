// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800BDDC0(s32, M2C_UNK *);              /* extern */
s32 func_80100304(M2C_UNK *);                       /* extern */
M2C_UNK func_80131AF8(s32, s32);                    /* extern */
extern M2C_UNK D_6000520;
extern M2C_UNK D_6001788;

void func_80000044(Actor *thisx, PlayState *play) {
    func_80131AF8(play, func_80100304(&D_6001788));
    func_800BDDC0(play, &D_6000520);
}
