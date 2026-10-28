// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_60040E0;
extern M2C_UNK D_8099AC10;

void func_80003DA0(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x420) = &D_8099AC10;
    func_80137934(arg0 + 0x194, &D_60040E0, 0xC0A00000, arg0);
}
