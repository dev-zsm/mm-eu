// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0303.h"

extern M2C_UNK D_80A0737C;

void func_800014D8(ObjSkateblock *this) {
    M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80A0737C;
    M2C_FIELD(this, f32 *, 0x160) = (f32) M2C_FIELD(this, f32 *, 0x28);
    M2C_FIELD(this, f32 *, 0x68) = (f32) M2C_FIELD(this, f32 *, 0x74);
}
