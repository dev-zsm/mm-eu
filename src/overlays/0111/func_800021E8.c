// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_600A450;
extern M2C_UNK D_808D5724;

void func_800021E8(u8 *arg0) {
    func_80137828(arg0 + 0x144, &D_600A450, 0xC0800000, arg0);
    M2C_FIELD(arg0, s8 *, 0x3EF) = 5;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808D5724;
}
