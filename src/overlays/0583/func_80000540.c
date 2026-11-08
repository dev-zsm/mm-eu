// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0583.h"

extern M2C_UNK D_80BC033C;

void func_80000540(Actor *thisx) {
    M2C_FIELD(thisx, s16 *, 0x21A) = 1;
    M2C_FIELD(thisx, M2C_UNK **, 0x200) = &D_80BC033C;
}
