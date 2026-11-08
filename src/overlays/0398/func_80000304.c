// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0398.h"

extern M2C_UNK func_80AA62BC;

void func_80000304(Actor *thisx) {
    M2C_FIELD(thisx, s16 *, 0xC0) = 0;
    M2C_FIELD(thisx, M2C_UNK **, 0x188) = &func_80AA62BC;
}
