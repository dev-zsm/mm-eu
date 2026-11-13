#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF30C(u8 *, u8 *);              /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, f32, f32, f32, s32, f32); /* extern */
M2C_UNK func_808F0BEC(u8 *);                      /* extern */
extern M2C_UNK D_60002B8;
extern M2C_UNK D_808F1C0C;

void func_8000118C(u8 *arg0) {
    func_80137788(arg0 + 0x144, &D_60002B8, 0.0f, 0.0f, 0.0f, 2, 0.0f);
    func_808F0BEC(arg0);
    M2C_FIELD(arg0, s16 *, 0xBC) = -0x4000;
    M2C_FIELD(arg0, s16 *, 0x1EE) = 0xC8;
    M2C_FIELD(arg0, s32 *, 0x120) = 0;
    M2C_FIELD(arg0, f32 *, 0xCC) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x1F0) = 0.0f;
    func_800FF30C(arg0 + 0x24, arg0 + 8);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808F1C0C;
}
