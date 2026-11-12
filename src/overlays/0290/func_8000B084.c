#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
f32 func_8017A844(f32);                         /* extern */
extern M2C_UNK D_6019E48;
extern M2C_UNK D_809E47B0;

void func_8000B084(u8 *arg0, M2C_UNK arg1) {
    s32 temp_f8;

    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809E47B0;
    func_80137934(arg0 + 0x190, &D_6019E48, 0xC1A00000, arg0);
    temp_f8 = (s32) (func_8017A844(1.5e+02f) + 60.0f);
    M2C_FIELD(arg0, s16 *, 0x154) = (s16) temp_f8;
    M2C_FIELD(arg0, f32 *, 0x1870) = 1.0f;
}
