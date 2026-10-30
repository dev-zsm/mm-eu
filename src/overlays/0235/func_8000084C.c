// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800BDD44(M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_6000960;

void func_8000084C(Actor *thisx, PlayState *play) {
    func_800BDD44(play, &D_6000960, play);
}
