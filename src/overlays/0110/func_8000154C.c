// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013796C(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_60041F4;
extern M2C_UNK D_808D12EC;

void func_8000154C(u8 *arg0) {
    func_8013796C(arg0 + 0x144, &D_60041F4, 0x40900000, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808D12EC;
    M2C_FIELD(arg0, f32 *, 0x70) = 5.0f;
}
