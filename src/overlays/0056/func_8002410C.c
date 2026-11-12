#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0056.h"

M2C_UNK func_800FEE3C(u8 *, f32, M2C_UNK);    /* extern */
s32 func_80136480(s32, u8 *);                     /* extern */
M2C_UNK func_80834A8C(s32, u8 *);                 /* extern */
M2C_UNK func_80846CA8(u8 *);                      /* extern */

void func_8002410C(u8 *arg0, s32 arg1) {
    func_80846CA8(arg0);
    func_800FEE3C(arg0 + 0xAD0, 0, 0x3ECCCCCD);
    if ((func_80136480(arg1, arg0 + 0x240) != 0) && (M2C_FIELD(arg0, f32 *, 0xAD0) < 10.0f)) {
        func_80834A8C(arg1, arg0);
    }
}
