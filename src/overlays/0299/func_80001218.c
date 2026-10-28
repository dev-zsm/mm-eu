// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B763C(s32, s32, M2C_UNK, M2C_UNK, f32, s32); /* extern */

void func_80001218(s32 arg0, s32 arg1) {
    func_800B763C(arg1, arg0, 0x41900000, 0x41700000, 0.0f, 0x45);
}
