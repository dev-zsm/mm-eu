// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800E0FAC(M2C_UNK, s32, s32, M2C_UNK);  /* extern */
extern M2C_UNK D_801E6EF0;

void func_8000014C(Actor *thisx, PlayState *play) {
    M2C_FIELD(&D_801E6EF0, u8 *, 0xF37) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF37) & 0xFE);
    func_800E0FAC(play, (u8 *)thisx + 0x188, thisx, play);
}
