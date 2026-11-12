#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF30C(u8 *, u8 *);              /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, f32, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_600033C;
extern M2C_UNK D_808AF720;

void func_800002CC(u8 *arg0) {
    f32 temp_f0;

    temp_f0 = (f32) func_80134AE8(&D_600033C);
    func_80137788(arg0 + 0x144, &D_600033C, 0.0f, temp_f0, temp_f0, 0, 0.0f);
    M2C_FIELD(arg0, s32 *, 0x308) = 0x80000088;
    M2C_FIELD(arg0, s32 *, 0x354) = 0x77CFFF77;
    if (M2C_FIELD(arg0, u8 *, 0xB7) != 0) {
        M2C_FIELD(arg0, u8 *, 0x2F8) = (u8) (M2C_FIELD(arg0, u8 *, 0x2F8) & 0xFFFE);
    }
    func_800FF30C(arg0 + 0x24, arg0 + 8);
    M2C_FIELD(arg0, M2C_UNK **, 0x230) = &D_808AF720;
}
