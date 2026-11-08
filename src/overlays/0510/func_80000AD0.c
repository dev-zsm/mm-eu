// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0510.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80B620B8;

void func_80000AD0(Actor *thisx) {
    func_800B8C4C(thisx, 0x389E);
    M2C_FIELD(thisx, M2C_UNK **, 0x2AC) = &D_80B620B8;
}
