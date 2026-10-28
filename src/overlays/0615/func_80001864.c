// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80BE609C();                                /* extern */
M2C_UNK func_80BE72AC(u8 *);                      /* extern */

void func_80001864(u8 *arg0) {
    if ((func_80BE609C() == 0) && (M2C_FIELD(arg0, s16 *, 0x2AE) == 0)) {
        func_80BE72AC(arg0);
    }
}
