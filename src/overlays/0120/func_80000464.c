// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800BDD44(s32, M2C_UNK *);              /* extern */
M2C_UNK func_808E136C(u8 *, s32);                 /* extern */
extern M2C_UNK D_6000A00;
extern M2C_UNK D_6000D78;

void func_80000464(Actor *thisx, PlayState *play) {
    if (M2C_FIELD(thisx, s16 *, 0x162) != 1) {
        func_800BDD44(play, &D_6000A00);
        func_800BDD44(play, &D_6000D78);
    }
    func_808E136C(thisx, play);
}
