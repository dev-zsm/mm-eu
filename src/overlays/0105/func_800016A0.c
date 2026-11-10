#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_6000E64;
extern M2C_UNK D_808C5D78;

void func_800016A0(u8 *arg0) {
    func_80137788(arg0 + 0x144, &D_6000E64, 0x3F800000, 0, 10.0f, 2, -3.0f);
    M2C_FIELD(arg0, s16 *, 0x2EE) = 0;
    M2C_FIELD(arg0, s16 *, 0x2EA) = 0;
    M2C_FIELD(arg0, f32 *, 0x70) = 8.0f;
    func_800B8C4C(arg0, 0x3AB3);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808C5D78;
}
