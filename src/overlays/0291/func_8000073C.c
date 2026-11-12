#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0291.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_80134AE8(s32);                             /* extern */
M2C_UNK func_80137788(s32, s32, f32, M2C_UNK, f32, s32, f32); /* extern */
extern M2C_UNK D_809EFB4C;
extern s32 D_809F11F8;

void func_8000073C(u8 *arg0) {
    func_80137788(arg0 + 0x148, D_809F11F8, 0.0f, 0x42380000, (f32) func_80134AE8(D_809F11F8), 2, 0.0f);
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809EFB4C;
    func_800B8C4C(arg0, 0x6858);
    func_800B8C4C(arg0, 0x2880);
    M2C_FIELD(arg0, s16 *, 0x2F8) = 0;
    M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x2F0) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x2F4) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0xC4) = 0.0f;
}
