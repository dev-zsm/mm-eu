// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0325.h"

extern M2C_UNK D_80A21C30;

void func_800009E4(ObjVspinyroll *this) {
    M2C_FIELD(this, M2C_UNK **, 0x390) = &D_80A21C30;
    M2C_FIELD(this, f32 *, 0x70) = 0.0f;
}
