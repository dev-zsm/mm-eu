#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEE3C(u8 *, f32, M2C_UNK);    /* extern */
s32 func_80137070(u8 *);                          /* extern */
M2C_UNK func_808C4A64(u8 *);                      /* extern */
M2C_UNK func_808C60D8(u8 *);                      /* extern */

void func_80001D5C(u8 *arg0, M2C_UNK arg1) {
    func_808C4A64(arg0);
    func_800FEE3C(arg0 + 0x70, 0, 0x3F000000);
    if (func_80137070(arg0 + 0x144) != 0) {
        M2C_FIELD(arg0, u8 *, 0x819) = (u8) (M2C_FIELD(arg0, u8 *, 0x819) | 1);
        func_808C60D8(arg0);
    }
}
