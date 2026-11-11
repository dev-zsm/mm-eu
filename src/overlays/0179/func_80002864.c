#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0179.h"

M2C_UNK func_80151DF4(M2C_UNK, u16, u8 *, M2C_UNK); /* extern */

void func_80002864(u8 *arg0, M2C_UNK arg1) {
    u16 temp_a1;

    temp_a1 = (M2C_FIELD(arg0, u16 *, 0x552) + 1) & 0xFFFF;
    func_80151DF4(arg1, temp_a1, arg0, arg1);
    M2C_FIELD(arg0, u16 *, 0x552) = temp_a1;
}

