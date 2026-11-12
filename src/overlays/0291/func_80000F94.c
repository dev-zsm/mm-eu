#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_80134AE8(s32);                             /* extern */
M2C_UNK func_80137788(u8 *, s32, M2C_UNK, f32, f32, s32, f32); /* extern */
M2C_UNK func_809EF770(u8 *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK D_809F0A70;
extern s32 D_809F11F8;

void func_80000F94(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_809F0A70;
    func_80137788(arg0 + 0x148, D_809F11F8, 0x3F800000, 0.0f, (f32) func_80134AE8(D_809F11F8), 2, 0.0f);
    func_800B8C4C(arg0, 0x6858);
    func_800B8C4C(arg0, 0x287F);
    func_809EF770(arg0, 2, 0x1E);
}
