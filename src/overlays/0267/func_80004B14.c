// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6003008;
extern M2C_UNK D_8099B994;

void func_80004B14(u8 *arg0, M2C_UNK arg1) {
    func_80137828(arg0 + 0x194, &D_6003008, 0xC0A00000, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x420) = &D_8099B994;
    M2C_FIELD(arg0, s16 *, 0x14A) = 0x32;
}
