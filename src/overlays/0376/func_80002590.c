// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1944(s16, u8 *);                 /* extern */
s32 func_800F1984(s16, u8 *);                     /* extern */
M2C_UNK func_800F1A08(s16, u8 *);                 /* extern */

void func_80002590(u8 *arg0, M2C_UNK arg1) {
    if (func_800F1984(M2C_FIELD(arg0, s16 *, 0x184), arg0) != 0) {
        func_800F1A08(M2C_FIELD(arg0, s16 *, 0x184), arg0);
        M2C_FIELD(arg0, M2C_UNK (**)(u8 *), 0x17C)(arg0);
        return;
    }
    func_800F1944(M2C_FIELD(arg0, s16 *, 0x184), arg0);
}
