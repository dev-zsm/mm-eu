// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_800BE288(u8 *, u8 *);              /* extern */
M2C_UNK func_801378E0(s32, M2C_UNK *);              /* extern */
extern M2C_UNK D_6004628;
extern M2C_UNK D_80AFD1BC;
extern M2C_UNK D_80AFE5E0;

void func_800018C4(u8 *arg0) {
    func_801378E0(arg0 + 0x144, &D_6004628);
    func_800BC8F4(arg0, 0x4000, 0xFF, 0, 0x14);
    M2C_FIELD(arg0, u8 *, 0x33D) = (u8) (M2C_FIELD(arg0, u8 *, 0x33D) & 0xFFFE);
    M2C_FIELD(arg0, s16 *, 0x28C) = 0x14;
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80AFE5E0;
    M2C_FIELD(arg0, f32 *, 0x5C) = (f32) M2C_FIELD(arg0, f32 *, 0x58);
    M2C_FIELD(arg0, f32 *, 0x70) = 10.0f;
    func_800BE288(arg0, arg0 + 0x32C);
    if (M2C_FIELD(arg0, s16 *, 0x1C) == 1) {
        func_800B8C4C(arg0, 0x39FA);
    } else {
        func_800B8C4C(arg0, 0x39F9);
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x280) = &D_80AFD1BC;
}
