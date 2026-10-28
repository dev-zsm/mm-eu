// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8094E178(u8 *);                      /* extern */

void func_80000F3C(u8 *arg0, s16 arg1) {
    func_8094E178(arg0);
    M2C_FIELD(arg0, s16 *, 0x2C2) = arg1;
}
