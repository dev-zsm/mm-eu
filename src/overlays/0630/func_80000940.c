// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800BDD44(s32, M2C_UNK *);              /* extern */
M2C_UNK func_80131AF8(s32, s32, u8 *);            /* extern */
extern M2C_UNK D_600C308;

void func_80000940(Actor *thisx, PlayState *play) {
    func_80131AF8(play, M2C_FIELD(thisx, s32 *, 0x15C), thisx);
    func_800BDD44(play, &D_600C308);
}
