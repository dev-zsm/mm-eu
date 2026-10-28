// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_8091CF34;

void func_80001718(u8 *arg0) {
    func_800B6564(arg0, 0x3C23D70A);
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_8091CF34;
}
