// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

u8 *func_8091BFE8();                              /* extern */

void func_800008D8(void) {
    u8 *temp_v0;

    temp_v0 = func_8091BFE8();
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s8 *, 0x200) = 1;
    }
}
