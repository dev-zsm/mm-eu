// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6000A74;
extern M2C_UNK D_80AA8380;

void func_80000EF8(u8 *arg0) {
    func_80137828(arg0 + 0x148, &D_6000A74, 0xC0A00000, arg0);
    func_800B8C4C(arg0, 0x38AD);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    M2C_FIELD(arg0, s16 *, 0x192) = 0xA;
    M2C_FIELD(arg0, M2C_UNK **, 0x18C) = &D_80AA8380;
}
