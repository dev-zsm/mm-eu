// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80151DF4(M2C_UNK, M2C_UNK, u8 *, M2C_UNK); /* extern */
extern M2C_UNK D_80B84E5C;

void func_8000086C(u8 *arg0, M2C_UNK arg1) {
    func_80151DF4(arg1, 0x120C, arg0, arg1);
    M2C_FIELD(arg0, M2C_UNK **, 0x314) = &D_80B84E5C;
}
