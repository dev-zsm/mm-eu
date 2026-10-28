// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137788(u8 *, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_6002190;
extern M2C_UNK D_80C04E58;

void func_8000034C(u8 *arg0) {
    func_80137788(arg0 + 0x1E4, &D_6002190, 0xBECCCCCD, M2C_FIELD(arg0, f32 *, 0x1FC) - 1.0f, 0.0f, 3, 0.0f);
    M2C_FIELD(arg0, u8 *, 0x154) = (u8) (M2C_FIELD(arg0, u8 *, 0x154) & 0xFFFB);
    M2C_FIELD(arg0, M2C_UNK **, 0x228) = &D_80C04E58;
}
