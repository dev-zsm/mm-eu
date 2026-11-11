#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0332.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BB80C(s32, u8 *);                 /* extern */
M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80A2A324(u8 *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK D_80A2C118;
extern f32 D_80A2DB04;

void func_80001F38(u8 *arg0, s32 arg1) {
    s16 temp_v1;

    func_80A2A324(arg0, 5, 0);
    func_800BC8F4(arg0, 0x4000, 0xFF, 0, 8);
    M2C_FIELD(arg0, s16 *, 0x3B2) = 0x14;
    if ((M2C_FIELD(arg0, s16 *, 0x3B6) != 0) && ((s32) M2C_FIELD(arg0, u8 *, 0xB7) <= 0)) {
        func_800BB80C(arg1, arg0);
        func_800B8C4C(arg0, 0x38AA);
        M2C_FIELD(arg0, s16 *, 0x3B2) = 0;
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    } else {
        func_800B8C4C(arg0, 0x38A9);
    }
    M2C_FIELD(arg0, f32 *, 0x3D4) = (f32) D_80A2DB04;
    M2C_FIELD(arg0, s32 *, 0x740) = 0;
    M2C_FIELD(arg0, s16 *, 0x3C6) = 0;
    if ((M2C_FIELD(arg0, s16 *, 0x752) != 0) && ((temp_v1 = M2C_FIELD(arg0, s16 *, 0x754), (temp_v1 == 0)) || (temp_v1 == 0x14))) {
        M2C_FIELD(arg0, s16 *, 0x3B2) = 0;
    }
    M2C_FIELD(arg0, s16 *, 0x3C0) = 0x4E20;
    if ((M2C_FIELD(arg0, s16 *, 0x752) != 0) && (M2C_FIELD(arg0, s16 *, 0x754) == 0xB)) {
        M2C_FIELD(arg0, s16 *, 0x3C0) = 0;
        M2C_FIELD(arg0, s16 *, 0x3B2) = 0;
    }
    M2C_FIELD(arg0, s16 *, 0x3B0) = 4;
    M2C_FIELD(arg0, M2C_UNK **, 0x3AC) = &D_80A2C118;
}
