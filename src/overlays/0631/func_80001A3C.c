// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80BF0030(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80BF1AA4;

void func_80001A3C(u8 *arg0) {
    func_80BF0030(arg0, 0x17);
    M2C_FIELD(arg0, M2C_UNK **, 0x284) = &D_80BF1AA4;
}
