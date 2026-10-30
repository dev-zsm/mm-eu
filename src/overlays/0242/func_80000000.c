// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

extern M2C_UNK D_8097F7C4;

void func_80000000(Actor *thisx, PlayState *play) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(thisx, s16 *, 0x1C);
    M2C_FIELD(thisx, s8 *, 0x144) = 0;
    M2C_FIELD(thisx, s16 *, 0x146) = (s16) ((temp_v0 >> 8) & 0xFF);
    M2C_FIELD(thisx, s8 *, 0x145) = (s8) ((temp_v0 >> 7) & 1);
    M2C_FIELD(thisx, s16 *, 0x1C) = (s16) (temp_v0 & 0x7F);
    if (M2C_FIELD(thisx, s16 *, 0x146) == 3) {
        M2C_FIELD(thisx, M2C_UNK **, 0x13C) = &D_8097F7C4;
    }
}
