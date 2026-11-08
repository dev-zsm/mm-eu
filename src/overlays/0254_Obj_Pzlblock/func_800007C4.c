// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0254.h"

extern M2C_UNK D_80988900;

void func_800007C4(ObjPzlblock *this) {
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80988900;
    M2C_FIELD(this, s32 *, 0x160) = 5;
}
