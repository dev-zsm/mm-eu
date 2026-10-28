// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_801238D0(u8 *);                          /* extern */
M2C_UNK func_808360A4(u8 *);                      /* extern */

void func_80008FCC(u8 *arg0) {
    func_808360A4(arg0);
    if (func_801238D0(arg0) != 0) {
        M2C_FIELD(arg0, s16 *, 0xAE8) = 1;
    }
}
