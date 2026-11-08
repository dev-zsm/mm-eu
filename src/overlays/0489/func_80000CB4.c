// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0489.h"

M2C_UNK func_80B28D54(u8 *);                      /* extern */

void func_80000CB4(Actor *thisx) {
    func_80B28D54(thisx);
    M2C_FIELD(thisx, s8 *, 0x30A) = 1;
}
