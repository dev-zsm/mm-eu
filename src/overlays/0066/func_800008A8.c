// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137884(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_60041F4;
extern M2C_UNK D_80874828;

void func_800008A8(u8 *arg0) {
    func_80137884(arg0 + 0x144, &D_60041F4, 0x40400000, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80874828;
    M2C_FIELD(arg0, f32 *, 0x70) = 3.0f;
}
