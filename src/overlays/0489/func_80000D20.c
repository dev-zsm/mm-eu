// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0489.h"

f32 func_80B28CA0(u8 *);                          /* extern */
M2C_UNK func_80B28D54(u8 *);                      /* extern */

void func_80000D20(Actor *thisx) {
    func_80B28D54(thisx);
    M2C_FIELD(thisx, f32 *, 0x310) = func_80B28CA0(thisx);
}
