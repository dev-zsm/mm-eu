// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0369.h"

extern M2C_UNK D_80A69C90;
extern M2C_UNK D_80A69E48;

void func_8000031C(ObjPurify *this) {
    M2C_FIELD(this, M2C_UNK **, 0x13C) = &D_80A69E48;
    M2C_FIELD(this, s32 *, 0x160) = 0;
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80A69C90;
}
