#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_60014B8;
extern M2C_UNK D_80AA7A18;

void func_80000594(u8 *arg0) {
    func_80137788(arg0 + 0x148, &D_60014B8, 0x3F000000, 0.0f, 0.0f, 1, -3.0f);
    M2C_FIELD(arg0, M2C_UNK **, 0x18C) = &D_80AA7A18;
}
