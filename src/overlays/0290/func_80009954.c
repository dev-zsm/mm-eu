#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0290.h"

M2C_UNK func_80137934(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
f32 func_8017A844(f32);                         /* extern */
extern M2C_UNK D_600A194;
extern M2C_UNK D_809E3078;

void func_80009954(u8 *arg0, M2C_UNK arg1) {
    f32 temp_f6;

    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809E3078;
    func_80137934(arg0 + 0x190, &D_600A194, 0xC1200000, arg0);
    temp_f6 = func_8017A844(5.0e+01f) + 70.0f;
    M2C_FIELD(arg0, s16 *, 0x152) = 0;
    M2C_FIELD(arg0, s16 *, 0x150) = (s16) (s32) temp_f6;
}
