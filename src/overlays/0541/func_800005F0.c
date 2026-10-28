// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BD9E0(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_80B8A7D4;
extern M2C_UNK D_80B8CE60;

void func_800005F0(u8 *arg0) {
    func_800BD9E0(arg0 + 0x190, &D_80B8CE60, 9);
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80B8A7D4;
}
