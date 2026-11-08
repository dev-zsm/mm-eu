// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0512.h"

extern M2C_UNK D_80B63D54;

void func_800005AC(BgIkanaBlock *this) {
    M2C_FIELD(this, u8 *, 0x17C) = (u8) (M2C_FIELD(this, u8 *, 0x17C) & 0xFFF8);
    M2C_FIELD(this, s8 *, 0x17D) = 0x28;
    M2C_FIELD(this, M2C_UNK **, 0x160) = &D_80B63D54;
}
