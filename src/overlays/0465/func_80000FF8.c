// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_800BE288(u8 *, u8 *);              /* extern */
M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_60008C0;
extern M2C_UNK D_80B00174;

void func_80000FF8(u8 *arg0) {
    func_80137828(arg0 + 0x144, &D_60008C0, 0xC0400000);
    if (M2C_FIELD(arg0, s32 *, 0x314) != 0) {
        func_800BE288(arg0, arg0 + 0x30C);
    }
    if (M2C_FIELD(arg0, u8 *, 0x18C) != 0) {
        M2C_FIELD(arg0, f32 *, 0x70) = 10.0f;
    }
    M2C_FIELD(arg0, u8 *, 0x191) = (u8) (M2C_FIELD(arg0, u8 *, 0x191) & 0xFFF4);
    func_800BC8F4(arg0, 0x4000, 0xFF, 0, 0x10);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80B00174;
}
