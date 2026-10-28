// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800FEC70(u8 *, s16, M2C_UNK);            /* extern */
s32 func_808AC63C(u8 *, s32);                     /* extern */
M2C_UNK func_808AC6B8(u8 *);                      /* extern */
M2C_UNK func_808ACB08(u8 *);                      /* extern */
M2C_UNK func_808ACC6C(u8 *);                      /* extern */

void func_80000A58(u8 *arg0, s32 arg1) {
    func_808AC6B8(arg0);
    if (func_808AC63C(arg0, arg1) != 0) {
        func_808ACC6C(arg0);
        return;
    }
    if (func_800FEC70(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x1E4), 0x200) != 0) {
        func_808ACB08(arg0);
    }
}
