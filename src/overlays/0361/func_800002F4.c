// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A55718;

void func_800002F4(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80A55718;
    M2C_FIELD(arg0, f32 *, 0x164) = 180.0f;
}
