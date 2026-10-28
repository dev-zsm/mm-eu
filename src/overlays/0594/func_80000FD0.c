// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80BCB1A8(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80BCBF78;

void func_80000FD0(u8 *arg0) {
    func_80BCB1A8(arg0, 9);
    M2C_FIELD(arg0, M2C_UNK **, 0x254) = &D_80BCBF78;
}
