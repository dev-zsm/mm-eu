// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801A3A68(M2C_UNK);                     /* extern */
extern M2C_UNK D_80ACFE78;

void func_800016F4(u8 *arg0) {
    func_801A3A68(0x25);
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80ACFE78;
}
