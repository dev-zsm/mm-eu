// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A81920;

void func_80001FB4(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80A81920;
    M2C_FIELD(arg0, f32 *, 0x16C) = (f32) M2C_FIELD(arg0, f32 *, 0x164);
}
