// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0594.h"

M2C_UNK func_80BCB1A8(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80BCBF78;

void func_80000FD0(Actor *thisx) {
    func_80BCB1A8(thisx, 9);
    M2C_FIELD(thisx, M2C_UNK **, 0x254) = &D_80BCBF78;
}
