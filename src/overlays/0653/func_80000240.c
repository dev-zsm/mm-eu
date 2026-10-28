// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80C04D28;
extern M2C_UNK D_80C06AA4;

void func_80000240(u8 *arg0) {
    M2C_FIELD(arg0, u8 *, 0x154) = (u8) (M2C_FIELD(arg0, u8 *, 0x154) & 0xFFFB);
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    func_800BD9E0(arg0 + 0x1E4, &D_80C06AA4, 2, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x228) = &D_80C04D28;
}
