#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0365.h"

M2C_UNK func_800FFBF8(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80A5DD64(u8 *, s32);                 /* extern */
extern f32 D_80A60458;

void func_80001C78(u8 *arg0, s32 arg1) {
    func_800FFBF8(arg0 + 0x378, 0x3D2C0831, 0x3E99999A, 0x3CF5C28F);
    func_800FFBF8(arg0 + 0xCC, 0x41880000, 0x3ECCCCCD, 0x40800000);
    if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
        M2C_FIELD(arg0, s8 *, 0x370) = 0;
        M2C_FIELD(arg0, f32 *, 0x378) = (f32) D_80A60458;
        M2C_FIELD(arg0, f32 *, 0xCC) = 17.0f;
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & 0xF7FFFFFF);
        func_80A5DD64(arg0, arg1);
    }
}
