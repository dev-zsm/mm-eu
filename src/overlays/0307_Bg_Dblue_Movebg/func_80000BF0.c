// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0307.h"

extern M2C_UNK D_80A0F3B8;

void func_80000BF0(BgDblueMovebg *this, PlayState *play) {
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80A0F3B8;
}
