// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_808CF040();                            /* extern */
M2C_UNK func_808CF4D4();                            /* extern */

void func_80001F0C(u8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C);
    switch (temp_v0) {                              /* irregular */
    case 0:
        func_808CF040();
        return;
    case 1:
    case 2:
        func_808CF4D4();
        return;
    }
}
