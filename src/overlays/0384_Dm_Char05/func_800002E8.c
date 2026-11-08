// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0384.h"

extern M2C_UNK D_80A917C8;

void func_800002E8(DmChar05 *this, s32 arg1) {
    M2C_FIELD(this, M2C_UNK **, 0x188) = &D_80A917C8;
}
