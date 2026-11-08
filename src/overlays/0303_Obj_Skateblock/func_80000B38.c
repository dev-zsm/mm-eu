// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0303.h"

void func_80000B38(ObjSkateblock *this, s32 arg1) {
    if ((arg1 == 0) || (arg1 == 1)) {
        M2C_FIELD(this, u8 **, 0x16C) = (u8 *) ((u8 *)this + 0x24);
    } else {
        M2C_FIELD(this, u8 **, 0x16C) = (u8 *) ((u8 *)this + 0x2C);
    }
    M2C_FIELD(this, s16 *, 0x170) = arg1;
}
