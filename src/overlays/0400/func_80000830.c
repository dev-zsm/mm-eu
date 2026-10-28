// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_60014B8;
extern M2C_UNK D_80AA7C94;

void func_80000830(u8 *arg0) {
    func_80137934(arg0 + 0x148, &D_60014B8, 0xC0A00000);
    M2C_FIELD(arg0, M2C_UNK **, 0x18C) = &D_80AA7C94;
}
