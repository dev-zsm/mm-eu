// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80A0548C;
extern M2C_UNK D_80A05C44;

void func_800008C0(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    func_800BD9E0(arg0 + 0x144, &D_80A05C44, 3, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x294) = &D_80A0548C;
}
