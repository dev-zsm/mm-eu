// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

s8 func_8013DCD4(M2C_UNK, s32);                     /* extern */
extern M2C_UNK D_80C016F8;

void func_80000880(Actor *thisx, PlayState *play) {
    M2C_FIELD(thisx, s8 *, 0x2AC) = func_8013DCD4(0x1A, play);
    M2C_FIELD(thisx, s8 *, 0x2AD) = func_8013DCD4(0x16, play);
    M2C_FIELD(thisx, M2C_UNK **, 0x188) = &D_80C016F8;
}
