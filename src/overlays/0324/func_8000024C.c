#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0324.h"

M2C_UNK func_800BBB30(u8 *, u8 *, u8 *, f32, s32, f32, s32, s32, s32); /* extern */
M2C_UNK func_800FFBF8(u8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK D_80A20130;
extern f32 D_80A210C4;
extern f32 D_80A210C8;

void func_8000024C(u8 *arg0, u8 *arg1) {
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) (M2C_FIELD(arg0, s16 *, 0x32) + 0x1518);
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) M2C_FIELD(arg0, s16 *, 0x32);
    if (!(M2C_FIELD(arg1, s32 *, 0x18840) & 7)) {
        func_800BBB30(arg1, arg0, arg0 + 0x24, M2C_FIELD(arg0, f32 *, 0xCC) - 20.0f, 0xA, 8.0f, 0x1F4, 0xA, 1);
    }
    func_800FFBF8(arg0 + 0xCC, 0x42480000, 0x3E99999A, 0x40A00000);
    func_800FFBF8(arg0 + 0xC4, 0x4528C000, 0x42C80000, 0x43FA0000);
    if (D_80A210C4 < M2C_FIELD(arg0, f32 *, 0xC4)) {
        M2C_FIELD(arg0, s16 *, 0x1B6) = 1;
        M2C_FIELD(arg0, f32 *, 0xC4) = (f32) D_80A210C8;
        M2C_FIELD(arg0, s16 *, 0x1B4) = 0x3C;
        M2C_FIELD(arg0, M2C_UNK **, 0x1AC) = &D_80A20130;
    }
}
