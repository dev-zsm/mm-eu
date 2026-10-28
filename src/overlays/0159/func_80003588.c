// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_809238A0(u8 *);                      /* extern */
M2C_UNK func_80923E3C();                            /* extern */
M2C_UNK func_809269A4(u8 *);                      /* extern */

void func_80003588(u8 *arg0, M2C_UNK arg1) {
    func_80923E3C();
    if ((M2C_FIELD(arg0, u16 *, 0x90) & 1) && (M2C_FIELD(arg0, f32 *, 0x68) < 0.0f)) {
        if ((M2C_FIELD(arg0, u8 *, 0x1E5) & 8) && ((M2C_FIELD(arg0, s16 *, 0x18) & 3) == 1)) {
            func_809238A0(arg0);
        }
        func_809269A4(arg0);
    }
}
