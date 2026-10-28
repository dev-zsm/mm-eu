// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_6000068;
extern M2C_UNK D_808CBB60;

void func_800001C0(u8 *arg0) {
    f32 temp_f0;

    temp_f0 = (f32) func_80134AE8(&D_6000068);
    func_80137788(arg0 + 0x144, &D_6000068, 0x3F800000, temp_f0, temp_f0, 2, 0.0f);
    M2C_FIELD(arg0, M2C_UNK **, 0x20C) = &D_808CBB60;
}
