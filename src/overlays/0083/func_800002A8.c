// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800B680C(u8 *);                      /* extern */
s32 func_800FED2C(s32, M2C_UNK, M2C_UNK, u8 *);   /* extern */

void func_800002A8(u8 *arg0, M2C_UNK arg1) {
    if (func_800FED2C(arg0 + 0x192, 0, 8, arg0) != 0) {
        func_800B6490(arg0);
        return;
    }
    M2C_FIELD(arg0, f32 *, 0x74) = -1.0f;
    func_800B680C(arg0);
}
