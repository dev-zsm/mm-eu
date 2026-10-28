// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

u8 *func_801812C4();                              /* extern */

void func_80000000(f32 arg0) {
    M2C_FIELD(func_801812C4(), f32 *, 0x34) = arg0;
}
