// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137070(u8 *, u8 *);              /* extern */

void func_8000032C(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x160) = (f32) M2C_FIELD(arg0, f32 *, 0x35C);
    func_80137070(arg0 + 0x144, arg0);
}
