// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_808D7138();                            /* extern */
M2C_UNK func_808D7334();                            /* extern */

void func_800004F4(u8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x14C);
    switch (temp_v0) {                              /* irregular */
    case 0:
        func_808D7138();
        return;
    case 1:
        func_808D7334();
        return;
    }
}
