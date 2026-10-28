// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137828(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6025878;
extern M2C_UNK D_809DC400;

void func_80002D08(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809DC400;
    func_80137828(arg0 + 0x190, &D_6025878, 0xC0A00000, arg0);
    M2C_FIELD(arg0, s16 *, 0x14C) = 0;
}
