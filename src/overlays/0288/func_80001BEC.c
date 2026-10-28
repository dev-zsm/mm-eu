// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137828(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6006E50;
extern M2C_UNK D_809D4E3C;

void func_80001BEC(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x170) = &D_809D4E3C;
    func_80137828(arg0 + 0x3C8, &D_6006E50, 0xC0A00000, arg0);
}
