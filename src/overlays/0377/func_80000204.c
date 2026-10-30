// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_8019FFD8(M2C_UNK, u8 *);             /* extern */
extern s32 D_801EAB9C;

void func_80000204(Actor *thisx, PlayState *play) {
    M2C_FIELD(thisx, M2C_UNK (**)(), 0x1A0)();
    if ((M2C_FIELD(play, s16 *, 0xA4) == 8) && (D_801EAB9C == 0) && (M2C_FIELD(play, u16 *, 0x1F34) == 0x1E0)) {
        func_8019FFD8(0x2879, play);
    }
}
