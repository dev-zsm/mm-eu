// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6002DD4;
extern M2C_UNK D_808BD5D8;

void func_80000C9C(u8 *arg0) {
    func_80137828(arg0 + 0x144, &D_6002DD4, 0xC0400000, arg0);
    M2C_FIELD(arg0, s16 *, 0x2BE) = 0x25;
    M2C_FIELD(arg0, s8 *, 0xB6) = 0x32;
    func_800B8C4C(arg0, 0x3880);
    M2C_FIELD(arg0, s16 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x20);
    M2C_FIELD(arg0, u8 *, 0x28D) = (u8) (M2C_FIELD(arg0, u8 *, 0x28D) & 0xFFFE);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808BD5D8;
}
