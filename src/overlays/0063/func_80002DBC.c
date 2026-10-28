// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_800BE350(u8 *, u8 *, M2C_UNK);     /* extern */
M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_6005D54;
extern M2C_UNK D_8086C324;

void func_80002DBC(u8 *arg0) {
    func_80137828(arg0 + 0x144, &D_6005D54, 0xC0400000);
    M2C_FIELD(arg0, s16 *, 0x2B6) = 0x14;
    M2C_FIELD(arg0, u8 *, 0x394) = (u8) (M2C_FIELD(arg0, u8 *, 0x394) & 0xFFFE);
    M2C_FIELD(arg0, u8 *, 0x395) = (u8) (M2C_FIELD(arg0, u8 *, 0x395) & 0xFFFE);
    M2C_FIELD(arg0, f32 *, 0x70) = 10.0f;
    func_800B8C4C(arg0, 0x38D3);
    func_800BC8F4(arg0, 0x4000, 0xFF, 0, 0x14);
    func_800BE350(arg0, arg0 + 0x384, 0);
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) (M2C_FIELD(arg0, s16 *, 0x32) + 0x8000);
    M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_8086C324;
}
