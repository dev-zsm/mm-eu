// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0570.h"

M2C_UNK func_80BB617C(u8 *);                      /* extern */

void func_80000260(Actor *thisx, s16 arg1) {
    func_80BB617C(thisx);
    M2C_FIELD(thisx, s16 *, 0x32C) = arg1;
}
