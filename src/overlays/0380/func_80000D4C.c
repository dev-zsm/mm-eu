#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0380.h"

M2C_UNK func_800BA9E4(s32, s32, M2C_UNK, M2C_UNK, f32, f32, s32, s32, s32, s32); /* extern */
M2C_UNK func_800FFAD8(s32, f32, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_80A8DC3C(u8 *, s32);                 /* extern */
extern M2C_UNK D_80A8DE24;
extern f32 D_80A8F81C;
extern f32 D_80A8F820;
extern s16 D_80A8FB56;

void func_80000D4C(u8 *arg0, s32 arg1) {
    if (D_80A8FB56 != 0) {
        func_800FFAD8(arg0 + 0x28, 0, 0x3D4CCCCD, 0x40C00000, D_80A8F81C);
        func_800FFAD8(arg0 + 0x348, 0, 0x3C23D70A, 0x3F000000, D_80A8F820);
        if ((s32) M2C_FIELD(arg0, f32 *, 0x28) >= 0) {
            D_80A8FB56 = 2;
            func_800BA9E4(arg1 + 0x1CA0, arg1, 0x183, 0x40A00000, 202.0f, 294.0f, 0, 0, 0, 0x80);
            M2C_FIELD(arg0, M2C_UNK **, 0x1A0) = &D_80A8DE24;
        }
    }
    func_80A8DC3C(arg0, arg1);
}
