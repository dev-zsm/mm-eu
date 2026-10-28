// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013DD78(M2C_UNK, u8 *, u8 *, M2C_UNK); /* extern */
M2C_UNK func_80B9652C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80B96A2C(u8 *);                      /* extern */
M2C_UNK func_80B96AA4(u8 *);                      /* extern */
M2C_UNK func_80B96D6C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80B96E28(u8 *, M2C_UNK);             /* extern */

void func_80001FD0(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, M2C_UNK), 0x188)(arg0, arg1);
    func_80B96D6C(arg0, arg1);
    func_80B96E28(arg0, arg1);
    func_80B96A2C(arg0);
    func_8013DD78(arg1, arg0 + 0x238, arg0 + 0x232, 3);
    func_80B96AA4(arg0);
    func_80B9652C(arg0, arg1);
}
