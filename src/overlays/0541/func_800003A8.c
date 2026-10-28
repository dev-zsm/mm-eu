// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80B8A598;
extern M2C_UNK D_80B8CE60;
extern f32 D_80B8D0D0;

void func_800003A8(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x70) = (f32) D_80B8D0D0;
    func_800BD9E0(arg0 + 0x190, &D_80B8CE60, 0xA, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80B8A598;
}
