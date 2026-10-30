// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800BDD44(s32, M2C_UNK *);              /* extern */
M2C_UNK func_800BDDC0(s32, M2C_UNK *);              /* extern */
extern M2C_UNK D_6001DB0;
extern M2C_UNK D_6001E40;

void func_80000850(Actor *thisx, PlayState *play) {
    func_800BDD44(play, &D_6001E40);
    func_800BDDC0(play, &D_6001DB0);
}
