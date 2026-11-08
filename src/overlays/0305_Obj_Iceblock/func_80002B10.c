// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0305.h"

extern M2C_UNK D_80A0A8EC;

void func_80002B10(ObjIceblock *this) {
    M2C_FIELD(this, M2C_UNK **, 0x1A8) = &D_80A0A8EC;
    M2C_FIELD(this, f32 *, 0x68) = 0.0f;
}
