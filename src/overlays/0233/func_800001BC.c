// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_80971810();                            /* extern */

void func_800001BC(u8 *arg0) {
    if ((M2C_FIELD(arg0, s32 *, 4) & 0x2000) != 0x2000) {
        func_80971810();
        func_800B6490(arg0);
    }
}
