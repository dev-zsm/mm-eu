#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0332.h"

M2C_UNK func_800FFBF8(u8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800FFCBC(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(u8 *, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
M2C_UNK func_80A2A324(u8 *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK D_60025F0;
extern M2C_UNK D_80A2B4C4;

void func_8000132C(u8 *arg0) {
    func_80A2A324(arg0, 2, 0);
    func_800FFBF8(arg0 + 0x3D4, 0x3C75C28F, 0x3D4CCCCD, 0x3A83126F);
    M2C_FIELD(arg0, s16 *, 0x3C0) = 0;
    M2C_FIELD(arg0, s16 *, 0x44C) = 0;
    M2C_FIELD(arg0, s16 *, 0x3B0) = 9;
    if (M2C_FIELD(arg0, s16 *, 0x3B6) >= 2) {
        func_80137788(arg0 + 0x278, &D_60025F0, 0x3F800000, 0.0f, (f32) func_80134AE8(&D_60025F0), 0, 0.0f);
        M2C_FIELD(arg0, s16 *, 0x3B6) = 3;
    }
    func_800FFCBC(arg0 + 0x3C2, 0xFF, 1, 5, 0);
    M2C_FIELD(arg0, M2C_UNK **, 0x3AC) = &D_80A2B4C4;
}
