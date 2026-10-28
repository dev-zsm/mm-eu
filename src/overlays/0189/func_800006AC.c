// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80954540(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80954A04;

void func_800006AC(u8 *arg0) {
    func_80954540(arg0, 7);
    M2C_FIELD(arg0, M2C_UNK **, 0x148) = &D_80954A04;
}
