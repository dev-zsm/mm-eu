// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_80B28CA0(u8 *);                          /* extern */
M2C_UNK func_80B28D54(u8 *);                      /* extern */

void func_80000B90(u8 *arg0) {
    func_80B28D54(arg0);
    M2C_FIELD(arg0, f32 *, 0x310) = func_80B28CA0(arg0);
}
