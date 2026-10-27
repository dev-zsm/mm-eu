// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80087C0C(M2C_UNK);                     /* extern */

void Sys_Freeze(void) {
loop_1:
    func_80087C0C(0x3E8);
    goto loop_1;
}
