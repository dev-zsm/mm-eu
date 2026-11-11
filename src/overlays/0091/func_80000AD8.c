#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0091.h"

M2C_UNK func_800FEE3C(s32, f32, M2C_UNK, u8 *); /* extern */
s32 func_80137070(u8 *);                          /* extern */
M2C_UNK func_808AFA38(u8 *);                      /* extern */
M2C_UNK func_808AFF00(u8 *);                      /* extern */

void func_80000AD8(u8 *arg0, M2C_UNK arg1) {
    func_800FEE3C(arg0 + 0x70, 0, 0x3F000000, arg0);
    if (func_80137070(arg0 + 0x144) != 0) {
        if (M2C_FIELD(arg0, u8 *, 0xB7) == 0) {
            func_808AFF00(arg0);
            return;
        }
        M2C_FIELD(arg0, u8 *, 0x2F9) = (u8) (M2C_FIELD(arg0, u8 *, 0x2F9) | 1);
        func_808AFA38(arg0);
    }
}
