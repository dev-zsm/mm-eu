// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0305.h"

extern M2C_UNK D_80A0B410;

void func_80003634(ObjIceblock *this) {
    M2C_FIELD(this, M2C_UNK **, 0x1A8) = &D_80A0B410;
    M2C_FIELD(this, f32 *, 0x2A8) = 0.0f;
}
