#include "types.h"
#include "m2c_compat.h"

s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, f32, f32, f32, s32, f32); /* extern */
M2C_UNK func_808F0BEC(u8 *);                      /* extern */
extern M2C_UNK D_60002B8;
extern M2C_UNK D_808F194C;

void func_8000100C(u8 *arg0) {
    func_80137788(arg0 + 0x144, &D_60002B8, -3.0f, (f32) func_80134AE8(&D_60002B8), 0.0f, 2, -3.0f);
    func_808F0BEC(arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808F194C;
}
